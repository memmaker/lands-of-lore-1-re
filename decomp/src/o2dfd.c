/* o2dfd: Westwood WSA animation player (Open/Animate/Close, frame offsets and XOR delta application) */
/* FLAGS: -ml -3 -Y */
#include <string.h>
#include <mem.h>
#include <stdarg.h>

typedef struct {
    unsigned current_frame;
    unsigned total_frames;          /* +02 */
    int pixel_x, pixel_y;           /* +04 */
    unsigned pixel_width;           /* +08 */
    unsigned pixel_height;          /* +0a */
    unsigned largest_frame_size;    /* +0c */
    char far *delta_buffer;         /* +0e */
    char far *file_buffer;          /* +12 */
    char file_name[13];             /* +16 */
    int flags;                      /* +23 */
    int file_handle;                /* +25 */
    unsigned long anim_mem_size;    /* +27 */
} SysAnimHeaderType;                /* 0x2b bytes */

typedef struct {
    unsigned total_frames;
    unsigned pixel_x, pixel_y;
    unsigned pixel_width, pixel_height;
    unsigned largest_frame_size;
    int flags;                      /* +0c */
    unsigned long frame0_offset;    /* +0e */
    unsigned long frame0_end;       /* +12 */
} WSA_FileHeaderType;               /* 0x16 bytes */

#define WSA_FILE_HEADER_SIZE (sizeof(WSA_FileHeaderType) - 2 * sizeof(unsigned long))

#define ABS(x) ((x) < 0 ? -(x) : (x))

extern int g_3649;
char far *fn_2279_02b5(char far *p);
int fn_1809_0000(char far *name, int mode);
long fn_1809_084d(int h, void far *buf, long n);
long fn_1809_0e76(int h, long off, int whence);
void fn_1809_058d(int h);
long fn_203b_03b4(int type);
void far *fn_203b_0007(long size, int flags);
void fn_203b_0203(void far *p);
void far *fn_2037_0002(void far *p, long n);
void fn_2279_025b(void far *s, void far *d, long n);
int fn_232c_000c(void far *s, void far *d, int n);
char far *fn_215f_001d(int page);
void fn_1e76_0213(char far *dst, char far *delta, int width, int xor);
void fn_1e76_0029(char far *dst, char far *delta);
void fn_1ddc_0026(int x, int y, int w, int h, int a, int b, char far *buf, int c, void far *d, void far *e);
long ovr_2dfd_0052(char far *file_buffer, int frame);
long ovr_2dfd_0057(int file_handle, int frame, int palette_adjust);
int ovr_2dfd_005c(SysAnimHeaderType far *sys_header, int curr_frame, char far *dest_ptr);

void far *ovr_2dfd_0020(char far *file_name, char far *user_buffer, long user_buffer_size, int user_flags, char far *palette)
{
    int fh, anim_flags;
    int palette_adjust;
    unsigned offsets_size;
    unsigned frame0_size;
    long target_buffer_size, delta_buffer_size, file_buffer_size;
    long max_buffer_size, min_buffer_size;
    char far *sys_anim_header_buffer;
    char far *target_buffer;
    char far *delta_buffer, far *delta_back;
    SysAnimHeaderType far *sys_header;
    long tlong;
    WSA_FileHeaderType file_header;

    anim_flags = 0;
    fh = fn_1809_0000(file_name, 1);
    fn_1809_084d(fh, (char far *)&file_header, sizeof(WSA_FileHeaderType));
    if (file_header.flags & 1) {
        anim_flags |= 0x100;
        palette_adjust = 0x300;
        if (palette) {
            fn_1809_0e76(fh, sizeof(unsigned long) * file_header.total_frames, 1);
            fn_1809_084d(fh, palette, 0x300L);
        }
    } else {
        palette_adjust = 0;
    }
    if (file_header.flags & 2) anim_flags |= 0x200;
    file_buffer_size = fn_1809_0e76(fh, 0L, 2);
    if (file_header.frame0_offset) {
        tlong = file_header.frame0_end - file_header.frame0_offset;
        frame0_size = (unsigned)tlong;
    } else {
        anim_flags |= 0x40;
        frame0_size = 0;
    }
    file_buffer_size -= palette_adjust + frame0_size + WSA_FILE_HEADER_SIZE;
    if (user_flags & 2) {
        target_buffer_size = 0L;
    } else {
        anim_flags |= 0x10;
        target_buffer_size = (unsigned long)file_header.pixel_width * file_header.pixel_height;
    }
    delta_buffer_size = (unsigned long)file_header.largest_frame_size + 6;
    min_buffer_size = target_buffer_size + delta_buffer_size;
    max_buffer_size = min_buffer_size + file_buffer_size;
    if (user_buffer && user_buffer_size < min_buffer_size) {
fail:
        fn_1809_058d(fh);
        return 0;
    }
    if (!user_buffer) {
        if (user_flags & 1) {
            user_buffer_size = min_buffer_size;
        } else if (!user_buffer_size) {
            user_buffer_size = max_buffer_size;
        } else if (user_buffer_size < max_buffer_size) {
            user_buffer_size = min_buffer_size;
        } else {
            user_buffer_size = max_buffer_size;
        }
        if (fn_203b_03b4(0) < user_buffer_size) {
            if (fn_203b_03b4(0) < min_buffer_size) goto fail;
            user_buffer_size = min_buffer_size;
        }
        user_buffer = fn_203b_0007(user_buffer_size, 0x30);
        anim_flags |= 2;
    } else {
        user_buffer_size = ((user_flags & 1) || user_buffer_size < max_buffer_size) ? min_buffer_size : max_buffer_size;
        anim_flags |= 1;
    }
    sys_anim_header_buffer = user_buffer;
    target_buffer = fn_2037_0002(sys_anim_header_buffer, sizeof(SysAnimHeaderType));
    delta_buffer = fn_2037_0002(target_buffer, target_buffer_size);
    if (target_buffer_size) memset(target_buffer, 0, (unsigned)target_buffer_size);
    if (file_header.total_frames & 0x8000) {
        anim_flags |= 0x80;
        file_header.total_frames &= 0x7fff;
    }
    sys_header = (SysAnimHeaderType far *)sys_anim_header_buffer;
    sys_header->current_frame = sys_header->total_frames = file_header.total_frames;
    sys_header->pixel_x = file_header.pixel_x;
    sys_header->pixel_y = file_header.pixel_y;
    sys_header->pixel_width = file_header.pixel_width;
    sys_header->pixel_height = file_header.pixel_height;
    sys_header->anim_mem_size = user_buffer_size;
    sys_header->delta_buffer = delta_buffer;
    sys_header->largest_frame_size = (unsigned)delta_buffer_size - sizeof(SysAnimHeaderType);
    strcpy(sys_header->file_name, file_name);
    offsets_size = (file_header.total_frames + 2) << 2;
    if (user_buffer_size == max_buffer_size) {
        sys_header->file_buffer = fn_2037_0002(delta_buffer, (unsigned long)sys_header->largest_frame_size);
        fn_1809_0e76(fh, WSA_FILE_HEADER_SIZE, 0);
        fn_1809_084d(fh, sys_header->file_buffer, (unsigned long)offsets_size);
        fn_1809_0e76(fh, (unsigned long)(frame0_size + palette_adjust), 1);
        fn_1809_084d(fh, sys_header->file_buffer + offsets_size, file_buffer_size - offsets_size);
        if (ovr_2dfd_0052(sys_header->file_buffer, sys_header->total_frames + 1))
            anim_flags |= 8;
        else
            anim_flags |= 0x28;
    } else {
        if (ovr_2dfd_0057(fh, sys_header->total_frames + 1, palette_adjust))
            anim_flags |= 4;
        else
            anim_flags |= 0x24;
        sys_header->file_buffer = 0;
    }
    delta_back = fn_2037_0002(delta_buffer, (unsigned long)(sys_header->largest_frame_size - frame0_size));
    fn_1809_0e76(fh, (unsigned long)(offsets_size + palette_adjust + WSA_FILE_HEADER_SIZE), 0);
    fn_1809_084d(fh, delta_back, (unsigned long)frame0_size);
    if (anim_flags & 8) {
        sys_header->file_handle = -1;
        fn_1809_058d(fh);
    } else {
        sys_header->file_handle = fh;
    }
    fn_232c_000c(delta_back, delta_buffer, sys_header->largest_frame_size);
    sys_header->flags = anim_flags;
    return user_buffer;
}

void ovr_2dfd_0025(void far *handle)
{
    SysAnimHeaderType far *sys_header;

    sys_header = (SysAnimHeaderType far *)handle;
    if (sys_header->flags & 4) fn_1809_058d(sys_header->file_handle);
    if (handle && (sys_header->flags & 2)) fn_203b_0203(handle);
}

/* va_arg: the original loads each far pointer as `mov es,seg; add off,4; mov bx,off; mov ax/dx,[es:bx-2/-4]`,
   our BCC emits `add; les bx; mov eax,[es:bx-4]` (stdarg, cast-lvalue and typed-pointer variants all tried) */
/* C version: BCC 3.1 does not reproduce the original code from it (tools/inlasm.py) */
#if 0
int ovr_2dfd_002a(void far *handle, int frame_number, int x_pixel, int y_pixel, int page, int flags_and_prio, ...)
{
    SysAnimHeaderType far *sys_header;
    int total_frames;
    int distance;
    int search_dir;
    int search_frames;
    int loop;
    int prio;
    int fl;
    char far *frame_buffer;
    int oldpage;
    int direct_to_dest;
    va_list ap;
    void far *magic_cols;
    void far *magic;
    int curr_frame;

    sys_header = (SysAnimHeaderType far *)handle;
    total_frames = sys_header->total_frames;
    if (!handle || total_frames <= frame_number) return 0;
    x_pixel += sys_header->pixel_x;
    y_pixel += sys_header->pixel_y;
    if (sys_header->flags & 0x10) {
        frame_buffer = fn_2037_0002(sys_header, sizeof(SysAnimHeaderType));
        frame_buffer = fn_2279_02b5(frame_buffer);
        direct_to_dest = 0;
    } else {
        frame_buffer = fn_215f_001d(page);
        frame_buffer += y_pixel * 320 + x_pixel;
        direct_to_dest = 1;
    }
    if (sys_header->current_frame == total_frames) {
        if (!(sys_header->flags & 0x40)) {
            if (direct_to_dest)
                fn_1e76_0213(frame_buffer, sys_header->delta_buffer, sys_header->pixel_width, !(sys_header->flags & 0x200) ? 1 : 0);
            else
                fn_1e76_0029(frame_buffer, sys_header->delta_buffer);
        }
        sys_header->current_frame = 0;
    }
    curr_frame = sys_header->current_frame;
    distance = ABS(curr_frame - frame_number);
    search_dir = 1;
    if (frame_number > curr_frame) {
        search_frames = total_frames - frame_number + curr_frame;
        if (search_frames < distance && !(sys_header->flags & 0x20))
            search_dir = -1;
        else
            search_frames = distance;
    } else {
        search_frames = total_frames - curr_frame + frame_number;
        if (search_frames >= distance || (sys_header->flags & 0x20)) {
            search_dir = -1;
            search_frames = distance;
        }
    }
    if (search_dir > 0) {
        for (loop = 0; loop < search_frames; loop++) {
            curr_frame += search_dir;
            ovr_2dfd_005c(sys_header, curr_frame, frame_buffer);
            if (curr_frame == total_frames) curr_frame = 0;
        }
    } else {
        for (loop = 0; loop < search_frames; loop++) {
            if (!curr_frame) curr_frame = total_frames;
            ovr_2dfd_005c(sys_header, curr_frame, frame_buffer);
            curr_frame += search_dir;
        }
    }
    sys_header->current_frame = frame_number;
    if (sys_header->flags & 0x10) {
        oldpage = g_3649;
        g_3649 = page;
        prio = (flags_and_prio & 0xff00) >> 12;
        fl = flags_and_prio & 0xff;
        va_start(ap, flags_and_prio);
        magic_cols = va_arg(ap, void far *);
        magic = va_arg(ap, void far *);
        fn_1ddc_0026(x_pixel, y_pixel, sys_header->pixel_width, sys_header->pixel_height, 0, prio, frame_buffer, fl, magic_cols, magic);
        g_3649 = oldpage;
    }
    return 1;
}
#endif
int ovr_2dfd_002a(void far *handle, int frame_number, int x_pixel, int y_pixel, int page, int flags_and_prio, ...)
{
    char _l[38];
    _SI;   /* saved by the original */
    _DI;   /* saved by the original */
    asm mov di,[bp+0ah]
    asm db 66h	/* mov eax,[bp+0x6] */
    asm mov ax,[bp+6]
    asm db 66h	/* mov [bp-0x4],eax */
    asm mov word ptr _l+34,ax
    asm les bx,dword ptr _l+34
    asm mov ax,es:[bx+2]
    asm mov word ptr _l+32,ax
    asm db 66h	/* cmp dword [bp+0x6],0x0 */
    asm cmp word ptr [bp+6],0
    asm jz L_0029
    asm cmp word ptr _l+32,di
    asm jg L_002e
L_0029:
    asm db 33h, 0c0h	/* xor ax,ax */
L_002b:
    asm jmp Lret
L_002e:
    asm les bx,dword ptr _l+34
    asm mov ax,es:[bx+4]
    asm add [bp+0ch],ax
    asm les bx,dword ptr _l+34
    asm mov ax,es:[bx+6]
    asm add [bp+0eh],ax
    asm les bx,dword ptr _l+34
    asm test word ptr es:[bx+23h],10h
    asm jz L_007f
    asm db 66h	/* push dword 0x2b */
    asm push 2bh
    asm push word ptr _l+36
    asm push word ptr _l+34
    asm call far ptr fn_2037_0002
    asm add sp,8
    asm mov word ptr _l+18,dx
    asm mov word ptr _l+16,ax
    asm push word ptr _l+18
    asm push word ptr _l+16
    asm call far ptr fn_2279_02b5
    asm add sp,4
    asm mov word ptr _l+18,dx
    asm mov word ptr _l+16,ax
    asm mov word ptr _l+12,0
    asm jmp L_00a0
L_007f:
    asm push word ptr [bp+10h]
    asm call far ptr fn_215f_001d
    asm pop cx
    asm mov word ptr _l+18,dx
    asm mov word ptr _l+16,ax
    asm mov ax,[bp+0eh]
    asm db 69h, 0c0h, 40h, 1	/* imul ax,ax,0x140 */
    asm add ax,[bp+0ch]
    asm add word ptr _l+16,ax
    asm mov word ptr _l+12,1
L_00a0:
    asm les bx,dword ptr _l+34
    asm mov ax,es:[bx]
    asm cmp ax,word ptr _l+32
    asm jnz L_0112
    asm les bx,dword ptr _l+34
    asm test word ptr es:[bx+23h],40h
    asm jnz L_010a
    asm cmp word ptr _l+12,0
    asm jz L_00f1
    asm les bx,dword ptr _l+34
    asm test word ptr es:[bx+23h],200h
    asm jnz L_00cc
    asm mov ax,1
    asm jmp L_00ce
L_00cc:
    asm db 33h, 0c0h	/* xor ax,ax */
L_00ce:
    asm push ax
    asm les bx,dword ptr _l+34
    asm push word ptr es:[bx+8]
    asm les bx,dword ptr _l+34
    asm push word ptr es:[bx+10h]
    asm push word ptr es:[bx+0eh]
    asm push word ptr _l+18
    asm push word ptr _l+16
    asm call far ptr fn_1e76_0213
    asm add sp,0ch
    asm jmp L_010a
L_00f1:
    asm les bx,dword ptr _l+34
    asm push word ptr es:[bx+10h]
    asm push word ptr es:[bx+0eh]
    asm push word ptr _l+18
    asm push word ptr _l+16
    asm call far ptr fn_1e76_0029
    asm add sp,8
L_010a:
    asm les bx,dword ptr _l+34
    asm mov word ptr es:[bx],0
L_0112:
    asm les bx,dword ptr _l+34
    asm mov si,es:[bx]
    asm db 8bh, 0c6h	/* mov ax,si */
    asm db 2bh, 0c7h	/* sub ax,di */
    asm jnl L_0126
    asm db 8bh, 0c6h	/* mov ax,si */
    asm db 2bh, 0c7h	/* sub ax,di */
    asm neg ax
    asm jmp L_012a
L_0126:
    asm db 8bh, 0c6h	/* mov ax,si */
    asm db 2bh, 0c7h	/* sub ax,di */
L_012a:
    asm mov word ptr _l+30,ax
    asm mov word ptr _l+28,1
    asm db 3bh, 0feh	/* cmp di,si */
    asm jng L_0162
    asm mov ax,word ptr _l+32
    asm db 2bh, 0c7h	/* sub ax,di */
    asm db 3, 0c6h	/* add ax,si */
    asm mov word ptr _l+26,ax
    asm mov ax,word ptr _l+26
    asm cmp ax,word ptr _l+30
    asm jnl L_015a
    asm les bx,dword ptr _l+34
    asm test word ptr es:[bx+23h],20h
    asm jnz L_015a
    asm mov word ptr _l+28,0ffffh
    asm jmp L_0160
L_015a:
    asm mov ax,word ptr _l+30
    asm mov word ptr _l+26,ax
L_0160:
    asm jmp L_018a
L_0162:
    asm mov ax,word ptr _l+32
    asm db 2bh, 0c6h	/* sub ax,si */
    asm db 3, 0c7h	/* add ax,di */
    asm mov word ptr _l+26,ax
    asm mov ax,word ptr _l+26
    asm cmp ax,word ptr _l+30
    asm jnl L_017f
    asm les bx,dword ptr _l+34
    asm test word ptr es:[bx+23h],20h
    asm jz L_018a
L_017f:
    asm mov word ptr _l+28,0ffffh
    asm mov ax,word ptr _l+30
    asm mov word ptr _l+26,ax
L_018a:
    asm cmp word ptr _l+28,0
    asm jng L_01c3
    asm mov word ptr _l+24,0
    asm jmp L_01b9
L_0197:
    asm add si,word ptr _l+28
    asm push word ptr _l+18
    asm push word ptr _l+16
    asm push si
    asm push word ptr _l+36
    asm push word ptr _l+34
    ((void (far *)(void))ovr_2dfd_005c)();
    asm add sp,0ah
    asm cmp si,word ptr _l+32
    asm jnz L_01b6
    asm db 33h, 0f6h	/* xor si,si */
L_01b6:
    asm inc word ptr _l+24
L_01b9:
    asm mov ax,word ptr _l+24
    asm cmp ax,word ptr _l+26
    asm jl L_0197
    asm jmp L_01f4
L_01c3:
    asm mov word ptr _l+24,0
    asm jmp L_01ec
L_01ca:
    asm db 0bh, 0f6h	/* or si,si */
    asm jnz L_01d1
    asm mov si,word ptr _l+32
L_01d1:
    asm push word ptr _l+18
    asm push word ptr _l+16
    asm push si
    asm push word ptr _l+36
    asm push word ptr _l+34
    ((void (far *)(void))ovr_2dfd_005c)();
    asm add sp,0ah
    asm add si,word ptr _l+28
    asm inc word ptr _l+24
L_01ec:
    asm mov ax,word ptr _l+24
    asm cmp ax,word ptr _l+26
    asm jl L_01ca
L_01f4:
    asm les bx,dword ptr _l+34
    asm mov es:[bx],di
    asm les bx,dword ptr _l+34
    asm test word ptr es:[bx+23h],10h
    asm jnz L_0208
    asm jmp L_029e
L_0208:
    asm mov ax,g_3649
    asm mov word ptr _l+14,ax
    asm mov ax,[bp+10h]
    asm mov g_3649,ax
    asm mov ax,[bp+12h]
    asm and ax,0ff00h
    asm shr ax,0ch
    asm mov word ptr _l+22,ax
    asm mov ax,[bp+12h]
    asm and ax,0ffh
    asm mov word ptr _l+20,ax
    asm lea ax,[bp+14h]
    asm mov word ptr _l+10,ss
    asm mov word ptr _l+8,ax
    asm mov es,word ptr _l+10
    asm add word ptr _l+8,4
    asm mov bx,word ptr _l+8
    asm mov ax,es:[bx-2]
    asm mov dx,es:[bx-4]
    asm mov word ptr _l+6,ax
    asm mov word ptr _l+4,dx
    asm mov es,word ptr _l+10
    asm add word ptr _l+8,4
    asm mov bx,word ptr _l+8
    asm mov ax,es:[bx-2]
    asm mov dx,es:[bx-4]
    asm mov word ptr _l+2,ax
    asm mov word ptr _l,dx
    asm push word ptr _l+2
    asm push word ptr _l
    asm push word ptr _l+6
    asm push word ptr _l+4
    asm push word ptr _l+20
    asm push word ptr _l+18
    asm push word ptr _l+16
    asm push word ptr _l+22
    asm push 0
    asm les bx,dword ptr _l+34
    asm push word ptr es:[bx+0ah]
    asm les bx,dword ptr _l+34
    asm push word ptr es:[bx+8]
    asm push word ptr [bp+0eh]
    asm push word ptr [bp+0ch]
    asm call far ptr fn_1ddc_0026
    asm add sp,1ah
    asm mov ax,word ptr _l+14
    asm mov g_3649,ax
L_029e:
    asm mov ax,1
    asm jmp L_002b
Lret:
    ;
}

int ovr_2dfd_002f(void far *handle)
{
    SysAnimHeaderType far *sys_header;

    if (!handle) return 0;
    sys_header = (SysAnimHeaderType far *)handle;
    return sys_header->total_frames;
}

int ovr_2dfd_0034(void far *handle)
{
    SysAnimHeaderType far *sys_header;

    if (!handle) return 0;
    sys_header = (SysAnimHeaderType far *)handle;
    return sys_header->pixel_x;
}

int ovr_2dfd_0039(void far *handle)
{
    SysAnimHeaderType far *sys_header;

    if (!handle) return 0;
    sys_header = (SysAnimHeaderType far *)handle;
    return sys_header->pixel_y;
}

int ovr_2dfd_003e(void far *handle)
{
    SysAnimHeaderType far *sys_header;

    if (!handle) return 0;
    sys_header = (SysAnimHeaderType far *)handle;
    return sys_header->pixel_width;
}

int ovr_2dfd_0043(void far *handle)
{
    SysAnimHeaderType far *sys_header;

    if (!handle) return 0;
    sys_header = (SysAnimHeaderType far *)handle;
    return sys_header->pixel_height;
}

int ovr_2dfd_0048(void far *handle)
{
    SysAnimHeaderType far *sys_header;

    if (!handle) return 0;
    sys_header = (SysAnimHeaderType far *)handle;
    return sys_header->flags & 0x100;
}

unsigned long ovr_2dfd_004d(void far *handle)
{
    SysAnimHeaderType far *sys_header;

    if (!handle) return 0;
    sys_header = (SysAnimHeaderType far *)handle;
    return sys_header->anim_mem_size;
}

long ovr_2dfd_0052(char far *file_buffer, int frame)
{
    unsigned long frame0_size;
    unsigned long far *lptr;

    lptr = (unsigned long far *)file_buffer;
    if (*lptr)
        frame0_size = lptr[1] - *lptr;
    else
        frame0_size = 0;
    lptr += frame;
    if (*lptr)
        return *lptr - (frame0_size + WSA_FILE_HEADER_SIZE);
    else
        return 0L;
}

long ovr_2dfd_0057(int file_handle, int frame, int palette_adjust)
{
    unsigned long offset;

    fn_1809_0e76(file_handle, (frame << 2) + WSA_FILE_HEADER_SIZE, 0);
    if (fn_1809_084d(file_handle, (char far *)&offset, sizeof(unsigned long)) != sizeof(unsigned long))
        offset = 0L;
    offset += palette_adjust;
    return offset;
}

int ovr_2dfd_005c(SysAnimHeaderType far *sys_header, int curr_frame, char far *dest_ptr)
{
    char far *data_ptr, far *delta_back;
    int file_handle, palette_adjust;
    unsigned long frame_data_size, frame_offset;

    palette_adjust = (sys_header->flags & 0x100) ? 0x300 : 0;
    delta_back = sys_header->delta_buffer;
    if (sys_header->flags & 8) {
        frame_offset = ovr_2dfd_0052(sys_header->file_buffer, curr_frame);
        frame_data_size = ovr_2dfd_0052(sys_header->file_buffer, curr_frame + 1) - frame_offset;
        data_ptr = fn_2037_0002(sys_header->file_buffer, frame_offset);
        delta_back = fn_2037_0002(delta_back, sys_header->largest_frame_size - frame_data_size);
        fn_2279_025b(data_ptr, delta_back, frame_data_size);
    } else if (sys_header->flags & 4) {
        file_handle = sys_header->file_handle;
        fn_1809_0e76(file_handle, 0L, 0);
        frame_offset = ovr_2dfd_0057(file_handle, curr_frame, palette_adjust);
        frame_data_size = ovr_2dfd_0057(file_handle, curr_frame + 1, palette_adjust) - frame_offset;
        if (!frame_offset || !frame_data_size) return 0;
        fn_1809_0e76(file_handle, frame_offset, 0);
        delta_back = fn_2037_0002(delta_back, sys_header->largest_frame_size - frame_data_size);
        if (fn_1809_084d(file_handle, delta_back, frame_data_size) != frame_data_size) return 0;
    }
    fn_232c_000c(delta_back, sys_header->delta_buffer, sys_header->largest_frame_size);
    if (sys_header->flags & 0x10)
        fn_1e76_0029(dest_ptr, sys_header->delta_buffer);
    else
        fn_1e76_0213(dest_ptr, sys_header->delta_buffer, sys_header->pixel_width, 0);
    return 1;
}
