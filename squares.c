/* 
 * squares.c: draw random colored squares
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
	Point ca, cb;
	Rectangle r;
	Image *palette;
	long a,b;
	int ssx, ssy, siz;

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

	initdraw(nil, nil, "win2");

	a = b =  (lnrand(0xFF) << 24) + (lnrand(0xFF) << 16) + (lnrand(0xFF) << 8) + 0xFF;
	palette = allocimagemix(display, a, b);

	ssx = screen->r.max.x - screen->r.min.x;
	ssy = screen->r.max.y - screen->r.min.y;

	ca.x = screen->r.min.x + nrand(ssx);
	ca.y = screen->r.min.y + nrand(ssy);

	siz = 10 + nrand(10);

	cb.x = ca.x + siz;
	cb.y = ca.y + siz;

	r.min = ca;
	r.max = cb;

	while (1) {

		draw(screen, r, palette, nil, ZP);

		ca.x = screen->r.min.x + nrand(ssx);
		ca.y = screen->r.min.y + nrand(ssy);

		siz = 10 + nrand(10);

		cb.x = ca.x + siz;
		cb.y = ca.y + siz;

		r.min = ca;
		r.max = cb;

		/* Pick random values for red, green, blue but force alpha to 0xFF (opaque) */

		a = b =  (lnrand(0xFF) << 24) + (lnrand(0xFF) << 16) + (lnrand(0xFF) << 8) + 0xFF;

		palette = allocimagemix(display, a, b);

		flushimage(display,1);

		sleep(3);

	}

	closedisplay(display);
}
