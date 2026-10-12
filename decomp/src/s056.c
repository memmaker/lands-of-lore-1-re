/* s056: WW library -- rectangle outline from four lines */
void far fn_1e30_0209(int x1, int y1, int x2, int y2, int c);

void fn_1e54_0001(int x1, int y1, int x2, int y2, int c)
{
    fn_1e30_0209(x1, y1, x2, y1, c);
    fn_1e30_0209(x1, y2, x2, y2, c);
    fn_1e30_0209(x1, y1, x1, y2, c);
    fn_1e30_0209(x2, y1, x2, y2, c);
}
