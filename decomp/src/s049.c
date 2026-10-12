/* s049: WW library -- draw a shape object into its rectangle */
struct Obj {
    char pad0[0x10];
    void far *data;     /* 0x10 */
    char pad14[8];
    int frame;          /* 0x1c */
    int x, y, w, h;     /* 0x1e .. 0x24 */
};
extern int g_3649;
void far fn_1ebc_0111(int x1, int y1, int x2, int y2);
void far fn_1fd6_000a(int page, void far *data, int x, int y, int frame, int flags);
void far fn_1b63_0004(int x, int y, int w, int h, int c);
void far fn_1ebc_01ec(void);

void fn_1db2_0003(struct Obj far *o, int c)
{
    if (g_3649 == 0)
        fn_1ebc_0111(o->x, o->y, o->x + o->w, o->y + o->h);
    fn_1fd6_000a(g_3649, o->data, o->x, o->y, o->frame, 0);
    fn_1b63_0004(o->x, o->y, o->w, o->h, c);
    if (g_3649 == 0)
        fn_1ebc_01ec();
}
