/**
 * @file  CircularBufferTest.c
 * @brief Unittest for module CircularBuffer.
 */

/**
 * ---------------------------------------------------------------------------------------------------------------------
 * Includes
 * ---------------------------------------------------------------------------------------------------------------------
 */

#include <stdbool.h>
#include <stdio.h>
#include <CUnit/Basic.h>

#include "ICircularBuffer.h"

/**
 * ---------------------------------------------------------------------------------------------------------------------
 * Defines
 * ---------------------------------------------------------------------------------------------------------------------
 */

/**
 * @def   ARR_SIZE(x)
 * @brief Get number of elements in array (from Googles chromium project, apparently).
 */
#define ARR_SIZE(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

/**
 * ---------------------------------------------------------------------------------------------------------------------
 * Types
 * ---------------------------------------------------------------------------------------------------------------------
 */

/**
 * ---------------------------------------------------------------------------------------------------------------------
 * Prototypes
 * ---------------------------------------------------------------------------------------------------------------------
 */

int InitInterfaceSuite( void );
int CleanInterfaceSuite( void );

void Test_ICircularBuffer_Init( void );

/**
 * ---------------------------------------------------------------------------------------------------------------------
 * Variables
 * ---------------------------------------------------------------------------------------------------------------------
 */

/**
 * ---------------------------------------------------------------------------------------------------------------------
 * Functions
 * ---------------------------------------------------------------------------------------------------------------------
 */

/**
 * *********************************************************************************************************************
 * Function
 * *********************************************************************************************************************
 */
int InitInterfaceSuite( void )
{
    // Nothing to do for now
    return 0;
}

/**
 * *********************************************************************************************************************
 * Function
 * *********************************************************************************************************************
 */
int CleanInterfaceSuite( void )
{
    // Nothing to do for now
    return 0;
}

/**
 * ---------------------------------------------------------------------------------------------------------------------
 * Tests
 * ---------------------------------------------------------------------------------------------------------------------
 */

/**
 * *********************************************************************************************************************
 * Test
 * *********************************************************************************************************************
 */
void Test_ICircularBuffer_Init( void )
{
    CircularBuffer_t myBuffer;
    uint8_t          data;     // We do not need an actual buffer, since we're not writing to it in this test

   // Test bad input
    CU_ASSERT_FALSE( ICircularBuffer_Init( NULL, NULL, 0 )                   );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, NULL, 0 )              );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, NULL, 256 )            );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 0 ) );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, NULL, 256 )            );

    // Test valid input
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 256 ) );
    CU_ASSERT_EQUAL( myBuffer.bufferSize, 256               );
    CU_ASSERT_EQUAL( myBuffer.pBuffer,    (uint8_t*)&data );
    CU_ASSERT_EQUAL( myBuffer.pRead,      (uint8_t*)&data );  // Dangerzone, relying on implementation.
    CU_ASSERT_EQUAL( myBuffer.pWrite,     (uint8_t*)&data );  // Dangerzone, relying on implementation.

    // Test some valid and invalid buffer sizes (up to about 1TB, probably not reasonable)
    // Ugly asserts, but quickest way to print actual value it fails on...
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 2 )                   );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 4 )                   );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 8 )                   );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 16 )                  );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 32 )                  );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 64 )                  );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 128 )                 );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 256 )                 );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 512 )                 );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 1024 )                );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 2048 )                );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 4096 )                );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 8192 )                );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 16384 )               );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 32768 )               );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 65536 )               );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 131072 )              );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 262144 )              );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 524288 )              );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 1048576 )             );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 2097152 )             );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 4194304 )             );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 8388608 )             );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 16777216 )            );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 33554432 )            );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 67108864 )            );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 134217728 )           );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 268435456 )           );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 536870912 )           );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 1073741824 )          );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 2147483648 )          );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 4294967296 )          );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 8589934592 )          );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 17179869184 )         );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 34359738368 )         );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 68719476736 )         );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 137438953472 )        );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 274877906944 )        );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 549755813888 )        );
    CU_ASSERT_TRUE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 1099511627776 )       );

    // Test values around valid sizes (up to about 1TB, probably not reasonable)
    // Ugly asserts, but quickest way to print actual value it fails on...
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 1 )                   );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 3 )                   );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 7 )                   );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 15 )                  );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 31 )                  );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 63 )                  );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 127 )                 );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 255 )                 );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 511 )                 );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 1023 )                );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 2047 )                );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 4095 )                );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 8191 )                );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 16383 )               );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 32767 )               );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 65535 )               );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 131071 )              );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 262143 )              );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 524287 )              );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 1048575 )             );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 2097151 )             );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 4194303 )             );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 8388607 )             );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 16777215 )            );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 33554431 )            );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 67108863 )            );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 134217727 )           );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 268435455 )           );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 536870911 )           );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 1073741823 )          );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 2147483647 )          );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 4294967295 )          );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 8589934591 )          );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 17179869183 )         );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 34359738367 )         );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 68719476735 )         );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 137438953471 )        );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 274877906943 )        );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 549755813887 )        );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 1099511627775 )       );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 3 )                   );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 5 )                   );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 9 )                   );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 17 )                  );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 33 )                  );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 65 )                  );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 129 )                 );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 257 )                 );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 513 )                 );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 1025 )                );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 2049 )                );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 4097 )                );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 8193 )                );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 16385 )               );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 32769 )               );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 65537 )               );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 131073 )              );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 262145 )              );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 524289 )              );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 1048577 )             );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 2097153 )             );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 4194305 )             );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 8388609 )             );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 16777217 )            );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 33554433 )            );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 67108865 )            );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 134217729 )           );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 268435457 )           );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 536870913 )           );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 1073741825 )          );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 2147483649 )          );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 4294967297 )          );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 8589934593 )          );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 17179869185 )         );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 34359738369 )         );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 68719476737 )         );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 137438953473 )        );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 274877906945 )        );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 549755813889 )        );
    CU_ASSERT_FALSE( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, 1099511627777 )       );
}

/**
 * *********************************************************************************************************************
 * Test
 * *********************************************************************************************************************
 */
void Test_ICircularBuffer_GetCount( void )
{
    CircularBuffer_t myBuffer;
    uint8_t          data[ 32 ];

    // Dummy-variables for pushing- and popping data
    uint8_t          dummyBuffer[ 32 ];
    uint8_t          dummyData[ 32 ] = {
        0,   1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
        16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31
    };

    // Initialize circular buffer
    CU_ASSERT_TRUE_FATAL( ICircularBuffer_Init( &myBuffer, (uint8_t*)&data, sizeof( data ) ) );

    // Base case
    CU_ASSERT_EQUAL( ICircularBuffer_GetCount( &myBuffer ), 0 );

    // Without wraparound, from start
    ICircularBuffer_Push( &myBuffer, (uint8_t*)&dummyData, 10 );  // 10 bytes written
    CU_ASSERT_EQUAL( ICircularBuffer_GetCount( &myBuffer ), 10 ); // 0 bytes read

    // Without wraparound, in middle
    ICircularBuffer_Pop( &myBuffer, (uint8_t*)&dummyBuffer, 10 );
    ICircularBuffer_Push( &myBuffer, (uint8_t*)&dummyData,  12 ); // 22 bytes written
    CU_ASSERT_EQUAL( ICircularBuffer_GetCount( &myBuffer ), 12 ); // 10 bytes read

    // To end of data buffer
    ICircularBuffer_Push( &myBuffer, (uint8_t*)&dummyData,  10 ); // 32 bytes written
    CU_ASSERT_EQUAL( ICircularBuffer_GetCount( &myBuffer ), 22 ); // 10 bytes read

    // Wraparound
    ICircularBuffer_Push( &myBuffer, (uint8_t*)&dummyData,   1 ); // 33 bytes written
    CU_ASSERT_EQUAL( ICircularBuffer_GetCount( &myBuffer ), 23 ); // 10 bytes read

    // Wraparound
    ICircularBuffer_Pop( &myBuffer, (uint8_t*)&dummyBuffer, 10 );
    ICircularBuffer_Push( &myBuffer, (uint8_t*)&dummyData,   7 ); // 33 bytes written
    CU_ASSERT_EQUAL( ICircularBuffer_GetCount( &myBuffer ), 20 ); // 20 bytes read
}

/**
 * *********************************************************************************************************************
 * Test
 * *********************************************************************************************************************
 */
void Test_ICircularBuffer_Peek( void )
{
    CU_FAIL( "Not implemented..." );
}

/**
 * *********************************************************************************************************************
 * Test
 * *********************************************************************************************************************
 */
void Test_ICircularBuffer_Pop( void )
{
    CU_FAIL( "Not implemented..." );
}

/**
 * *********************************************************************************************************************
 * Test
 * *********************************************************************************************************************
 */
void Test_ICircularBuffer_Push( void )
{
    CU_FAIL( "Not implemented..." );
}

/**
 * *********************************************************************************************************************
 * Test
 * *********************************************************************************************************************
 */
void Test_ICircularBuffer_Clear( void )
{
    CU_FAIL( "Not implemented..." );
}

/**
 * ---------------------------------------------------------------------------------------------------------------------
 * Entrypoint
 * ---------------------------------------------------------------------------------------------------------------------
 */

int main()
{
    CU_pSuite pSuite = NULL;

    // Initialize CUnit registry
    if ( CUE_SUCCESS != CU_initialize_registry() )
    {
        return CU_get_error();
    }

    // Add suite to registry
    pSuite = CU_add_suite( "Interface", InitInterfaceSuite, CleanInterfaceSuite );
    if ( NULL == pSuite )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add tests to the suite
    if (
        ( NULL == CU_add_test( pSuite, "Test of ICircularBuffer_Init",      Test_ICircularBuffer_Init       ) ) ||
        ( NULL == CU_add_test( pSuite, "Test of ICircularBuffer_GetCount",  Test_ICircularBuffer_GetCount   ) ) ||
        ( NULL == CU_add_test( pSuite, "Test of ICircularBuffer_Peek",      Test_ICircularBuffer_Peek       ) ) ||
        ( NULL == CU_add_test( pSuite, "Test of ICircularBuffer_Pop",       Test_ICircularBuffer_Pop        ) ) ||
        ( NULL == CU_add_test( pSuite, "Test of ICircularBuffer_Push",      Test_ICircularBuffer_Push       ) ) ||
        ( NULL == CU_add_test( pSuite, "Test of ICircularBuffer_Clear",     Test_ICircularBuffer_Clear      ) )
    )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run all tests using CUnit basic interface
    CU_basic_set_mode( CU_BRM_VERBOSE );
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}