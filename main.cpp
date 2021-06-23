#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>


void myInit(void)
 {
    glClearColor(0.0,0.0,0.0,0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
 	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 800.0, 0.0, 400.0);
}


class GLintPoint
{
public:
		GLint x, y;
};


class Point2
{
public:
	float x,y;
	void set(float dx,float dy)
	{
		x = dx;
		y = dy;
	}
	void set(Point2 &p)
	{
		x = p.x;
		y = p.y;
	}
	Point2(float xx,float yy)
	{
		x = xx;
		y = yy;
	}
	Point2()
	{
		x = y = 0;
	}
};


GLintPoint CP;


float lerp (float a, float b, float t)
{
	return a + (b - a) *t;
}


Point2 Tween(Point2 A, Point2 B ,float t)
	{
		Point2 P;
		P.x = lerp(A.x,B.x,t);
		P.y = lerp(A.y,B.y,t);
		return P;
	}


void moveTo(GLint x ,GLint y)
{
	CP.x = x; CP.y = y;
}


void lineTo(GLint x ,GLint y)
{
	glBegin (GL_LINES);
	glVertex2i(CP.x,CP.y);
	glVertex2i(x,y);
	glEnd();
	glutSwapBuffers();
	CP.x = x; CP.y = y;
}


void drawTween (Point2 A[], Point2 B[], int n, float t)
{
     for (int i = 0; i < n; i++)
     {
        Point2 P;
        P = Tween (A[i], B[i], t);
        if (i == 0) moveTo (P.x, P.y);
        else lineTo (P.x, P.y);
       }
}


void myDisplay(void)
{
	int x;
	glClear(GL_COLOR_BUFFER_BIT);

	Point2 A[22];
		A [0].set(200,80);
		A [1].set(140,80);
		A [2].set(149.2,88.1);
		A [3].set(100,80);
		A [4].set(59.9,83.1);
		A [5].set(29.2,109.9);
		A [6].set(61,95.2);
		A [7].set(101,104.9);
		A [8].set(154.6,159.5);
		A [9].set(190.6,193.8);
		A [10].set(214.6,238.8);
		A [11].set(217.8,227);
		A [12].set(248.5,213.1);
		A [13].set(245.3,207);
		A [14].set(220.3,203.5);
		A [15].set(216.7,167);
		A [16].set(228.8,159.9);
		A [17].set(233.1,137.4);
		A [18].set(227.8,141);
		A [19].set(217.4,156.7);
		A [20].set(180.3,95.6);
		A [21].set(200,80);



	Point2 B[22];
		B [0].set (605.2,160.8);
		B [1].set (592.3,193.8);
		B [2].set (620,240);
		B [3].set (581.1,235.5);
		B [4].set (551.4,224.4);
		B [5].set (491,194.8);
		B [6].set (546.2,236.2);
		B [7].set (575.7,253.9);
		B [8].set (620,300);
		B [9].set (679.6,332.3);
		B [10].set (692.2,369);
		B [11].set (700.8,357.4);
		B [12].set (742.5,353);
		B [13].set (739.3,348.2);
		B [14].set (714.1,334);
		B [15].set (700,310);
		B [16].set (703.4,284.2);
		B [17].set (694.6,253.8);
		B [18].set (697,290.2);
		B [19].set (693.7,294.1);
		B [20].set (612.4,203.7);
		B [21].set (605.2,160.8);



	for(x=0;x<=10;x+=1)
	{
	    glColor3f(0.1*x, 1-0.1*x, 0);
	    glLineWidth(0.2*x);
		drawTween(A,B,22,0.1*x);
	}


	glFlush();
	glutSwapBuffers();
}

main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
	glutInitWindowSize(800,400);
	glutInitWindowPosition(100,150);
	glutCreateWindow("Kanguru Melompat Uhuy");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
