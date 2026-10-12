/* lol.h: shared game structures (layouts recovered from MAIN.EXE; names provisional) */

struct Attack { int hit; int dmgMul; int w4; int defense; int w8; };

/* combat stats block: embedded in a character, part of a monster type */
struct Stats {
    struct Attack far *atk;
    int dmg[8];              /* +04 damage per damage type */
    int res[7];              /* +14 resistances */
    int w22;                 /* +22 */
};

struct Char {                /* 0x82 bytes, f_2803_362d[4] */
    unsigned flags;          /* +00 1 present, 8 dead, 0x1000 mute */
    char name[0x0b];         /* +02 */
    char cD;                 /* +0d */
    int wE;                  /* +0e */
    char face;               /* +10 current face */
    char faceDef;            /* +11 default face */
    char voice;              /* +12 */
    struct Stats st;         /* +13 */
    int w37;                 /* +37 */
    int hp;                  /* +39 */
    int maxHp;               /* +3b */
    int mp;                  /* +3d */
    int maxMp;               /* +3f */
    char c41;                /* +41 */
    int lastDmg;             /* +42 */
    int dmgDealt;            /* +44 */
    int w46;                 /* +46 */
    int w48;                 /* +48 */
    int w4a;
    int w4c;                 /* +4c */
    int w4e;
    int items[11];           /* +50 equipment */
    char skill[3];           /* +66 */
    char skillBonus[3];      /* +69 */
    long exp[3];             /* +6c */
    char timer[5];           /* +78 status timers (ticks of timer 3) */
    char timerType[5];       /* +7d */
};

struct MonType {
    char pad00[0x14];
    struct Stats st;         /* +14 */
    int w38;                 /* +38 */
    int maxHp;               /* +3a */
    char pad3c;
    char evade;              /* +3d */
    unsigned flags;          /* +3e */
    char pad40[0x12];
    unsigned char sound;     /* +52 */
};

struct Monster {             /* 0x2e bytes, f_2803_15fa[30] */
    int next;                /* +00 next monster on the same block */
    char pad02[3];
    int block;               /* +05 */
    int x;                   /* +07 */
    int y;                   /* +09 */
    char pad0b[6];
    char dx;                 /* +11 */
    char dy;                 /* +12 */
    char pad13;
    char mode;               /* +14 >= 13: dead */
    char pad15[4];
    unsigned flags;          /* +19 */
    int hitDmg;              /* +1b */
    int hp;                  /* +1d */
    int pad1f;
    struct MonType far *type;/* +21 */
    char pad25[9];
};

struct Block { int items; int w2; int mon; int draw; char drawDir; unsigned char flags; };   /* items/w2 overlay char walls[4] */
#define WALL(b, d) (((char *)&g_8203[b])[d])   /* 10 bytes, g_8203[1024] */

struct Item {               /* 16 bytes, f_2803_1cfd[400] */
    int next;
    int drawNext;            /* +02 */
    unsigned char sub;       /* +04 position inside the block */
    int block;               /* +05 */
    int x, y;                /* +07 */
    unsigned char level;     /* +0b */
    int type;                /* +0c */
    unsigned flags;          /* +0e 0x4000 on floor, 0x8000 free */
};

struct ItemType { int name; unsigned char shape; unsigned flags; char pad5[2]; unsigned char script; unsigned char w8; char pad9[4]; };   /* 13 bytes */

struct Emc { int far *ip; char pad04[8]; int sp; int regs[15]; int stack[101]; };   /* EMC2 script state */

extern struct Char far f_2803_362d[];
extern struct Monster far f_2803_15fa[];

struct Fly {                /* 0x11 bytes, g_4dcc[8]: flying objects (thrown items, missiles) */
    char active;
    char type;
    int owner;               /* +02 */
    int item;                /* +04 */
    int x, y;                /* +06 */
    char power;              /* +0a */
    char dir;                /* +0b */
    char range;              /* +0c */
    char pad;
    char e;                  /* +0e */
    char flags;              /* +0f */
    char f10;                /* +10 */
};
extern struct Block g_8203[];
extern struct Item far f_2803_1cfd[];
extern struct ItemType far *g_7fb2;

#define ABS(x) ((x) < 0 ? -(x) : (x))
