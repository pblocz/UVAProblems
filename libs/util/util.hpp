/**
   \author Pablo Cabeza García

   Version 0.11.21

   This file is meant to provide some useful common idioms or tricks
   for contests or UVA online judge, as well as the most common set
   of libraries used from std.
*/


/* -----------------------------------------------------------
   Marco's trick to comment and uncomment two blocks in a fast
   way. 
   ----------------------------------------------------------- */

//* Add one slash to uncomment -> //* and erase it to comment -> /*
  int cosa(){}
/*/
int cosa2(){}
//*/


/* -----------------------------------------------------------
	   Min and Max functions for auto assignment
   ----------------------------------------------------------- */
template <typename T>
T& minl(T& lhs,const T& rhs){
    return lhs=std::min(lhs,rhs);
}

template <typename T>
T& maxl(T& lhs,const T& rhs){
    return lhs=std::max(lhs,rhs);
}


/* -----------------------------------------------------------
   Trick for printing test on computer and not on UVA, use as:
   dout << SOMETHING;
   ----------------------------------------------------------- */

/* Incomplete one just for <iostream> */
#ifdef ONLINE_JUDGE
	#define dout if(false) cout
#else
	#define dout cout
#endif

/* Complete one for <iostream> and <stdio.h> */
#ifdef ONLINE_JUDGE
	#define dout if(false) cout
	int dummy(...){return EOF;}
	#define dprintf dummy
#else
	#define dout cout
	#define dprintf printf
#endif



/* -----------------------------------------------------------
         Libraries mostly used by all problems in contests 
   ----------------------------------------------------------- */

/* C libraries */
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

/* IOStream Libraries */
#include <iostream>
#include <sstream>

/* String Class */
#include <string>

/* STL Containers */
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

/* STL Algorithms */
#include <algorithm>

/* Miscellaneous */
#include <complex>
#include <utility>
