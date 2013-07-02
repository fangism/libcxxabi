/**
	Provide a missing __eprintf symbol that was expected in 
	libstdc++ on darwin8 because in libc, it was (mistakenly?) given 
	static linkage.

% nm /usr/lib/libc.dylib
/usr/lib/libc.dylib(_eprintf.o):
90191c00 t ___eprintf

	references:
	http://www.opensource.apple.com/source/libstdcxx/libstdcxx-5.1/patches/eprintf.patch
	http://gcc.gnu.org/ml/libstdc++/2005-11/msg00183.html
 */
#ifdef	__APPLE__
#if (defined(__ppc__) || defined (__ppc64__))
// && defined (PIC)

#include <cassert>
#include <cstdio>
#include <cstdlib>

// using namespace std;
extern "C" {
void
__eprintf (const char *string, const char *expression,
	   unsigned int line, const char *filename)
{
  fprintf (stderr, string, expression, line, filename);
  fflush (stderr);
  abort ();
}

}

#endif
#endif
