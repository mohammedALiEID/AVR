/* 
 * File:   STD_data_types.h
 * Author: sayr3
 *
 * Created on February 29, 2024, 12:20 PM
 */

#ifndef STD_DATA_TYPES_H
#define	STD_DATA_TYPES_H


/*section:*********includes*******************************/


/*section:*********data types ***************************/
#define CPU_TYPE_8   8
#define CPU_TYPE_16  16
#define CPU_TYPE_32  32
#define CPU_TYPE_64  64
#define CPU_TYPE (CPU_TYPE_8)
#if (CPU_TYPE==CPU_TYPE_64)
typedef unsigned char boolean_ ;
typedef unsigned char uint_8 ;
typedef unsigned short uint_16 ;
typedef unsigned int uint_32 ;
typedef unsigned long long  uint_64 ;
typedef signed char sint_8 ;
typedef signed short sint_16 ;
typedef signed int sint_32 ;
typedef signed long long  sint_64 ;
typedef float  float_32 ;
typedef double  float_64 ;


#elif (CPU_TYPE==CPU_TYPE_32)


typedef unsigned char boolean_ ;
typedef unsigned char uint_8 ;
typedef unsigned short uint_16 ;
typedef unsigned long uint_32 ;
typedef unsigned long long  uint_64 ;
typedef signed char sint_8 ;
typedef signed short sint_16 ;
typedef signed long sint_32 ;
typedef signed long long  sint_64 ;
typedef float  float_32 ;
typedef double  float_64 ;



#elif (CPU_TYPE==CPU_TYPE_16)

typedef unsigned char boolean ;
typedef unsigned char uint_8 ;
typedef unsigned short uint_16 ;
typedef unsigned long uint_32 ;
typedef unsigned long long  uint_64 ;
typedef signed char sint_8 ;
typedef signed short sint_16 ;
typedef signed long sint_32 ;
typedef signed long long  sint_64 ;
typedef float  float_32 ;
typedef double  float_64 ;



#elif (CPU_TYPE==CPU_TYPE_8)


typedef unsigned char boolean_1 ;
typedef unsigned char uint_8 ;
typedef unsigned short uint_16 ;
typedef unsigned long uint_32 ;
typedef signed char sint_8 ;
typedef signed short sint_16 ;
typedef signed long sint_32 ;
typedef float  float_32 ;

#else 

#error 

#endif

typedef uint_8 Std_ReturnType ; 

/*section:*********macro declaration*********************/
#define STD_LOW     0x0 
#define STD_HIGH    0x1
#define STD_OFF     0x0
#define STD_ON      0x1
#define STD_IDLE    0x0
#define STD_ACTIVE  0x1  
#define E_NOT_OK   (Std_ReturnType)0x0
#define E_OK       (Std_ReturnType)0x1
#define ZERO_INT   0x0


/*section:*********macro functions declaration **********/




/*section:*********functions declaration*****************/


















#endif	/* STD_DATA_TYPES_H */

