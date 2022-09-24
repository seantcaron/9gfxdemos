/*
 * lines.c: draw random colored lines, starting over from scratch randomly
 * sean caron (scaron@umich.edu
*/

/*
  * The paradigm here is that we must always include u.h
  * first and libc.h second, and anything else after that.
*/

#include <u.h>
#include <libc.h>
#include <draw.h>
#include <cursor.h>

int main(void);

int main(void) {
    Point blah, blah2;
    Image *palette;
    long a,b;
    initdraw(nil, nil, "win2");
    int t;

    palette = allocimagemix(display, a, b);

    /*
     * initdraw() sets up some global variables,
     *
     * Display *display
     * Image *screen
     * Screen *_screen
     * Font *font
     *
     * ZP is a constant point (0,0).
    */

    blah.x = screen->r.min.x + nrand(screen->r.max.x);
    blah2.x = screen->r.min.x + nrand(screen->r.max.x);
    blah.y = blah2.y = screen->r.min.y + nrand(screen->r.max.y);

    while (1) {
        line(screen, blah, blah2, Endsquare, Endsquare, 2, palette, blah);

        /* draw a horizontal line */
        t = nrand(100);

        if ( t > 50 ) {
            blah.x = screen->r.min.x + nrand(screen->r.max.x);
            blah2.x = screen->r.min.x + nrand(screen->r.max.x);
            blah.y = blah2.y = screen->r.min.y + nrand(screen->r.max.y);
        }

        /* draw a vertical line */
        else if ( t < 50 ) {
            blah.y = screen->r.min.y + nrand(screen->r.max.y);
            blah2.y = screen->r.min.y + nrand(screen->r.max.y);
            blah.x = blah2.x = screen->r.min.x + nrand(screen->r.max.x);
        }
		
        /* clear the screen */
        else {
            draw(screen, screen->r, display->white, nil, ZP);
        }

        /* Pick random values for red, green, blue but force alpha to 0xFF (opaque) */
        a = b =  (lnrand(0xFF) << 24) + (lnrand(0x01) << 16) + (lnrand(0xFF) << 8) + 0xFF;

        palette = allocimagemix(display, a, b);

        flushimage(display, 1);

        sleep(10);
    }
	
    closedisplay(display);
}
