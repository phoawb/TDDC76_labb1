#include "catch.hpp"
#include "Time.h"

using namespace std;

TEST_CASE ("Constructors and getters")
{
   SECTION("Default")
   {
      Time empty{};
      REQUIRE( empty.get_hour()   == 0 );
      CHECK( empty.get_minute() == 0 );
      CHECK( empty.get_second() == 0 );
   }

   SECTION("Integer")
   {
      Time t0{0,0,0};
      Time t1{12,30,30};
      Time t2{23,59,59};

      CHECK_THROWS( Time{13,35,60} );
      CHECK_THROWS( Time{13,60,35} );
      CHECK_THROWS( Time{24,35,35} );
             
      CHECK( t0.get_hour()   == 0 );
      CHECK( t0.get_minute() == 0 );
      CHECK( t0.get_second() == 0 );
      CHECK( t1.get_hour()   == 12 );
      CHECK( t1.get_minute() == 30 );
      CHECK( t1.get_second() == 30 );
      CHECK( t2.get_hour()   == 23 );
      CHECK( t2.get_minute() == 59 );
      CHECK( t2.get_second() == 59 );
   }


   SECTION("String")
   {
      Time t0{"00:00:00"};
      Time t1{"12:30:30"};
      Time t2{"23:59:59"};

      CHECK_THROWS( Time{"13:35:60"} );
      CHECK_THROWS( Time{"13:60:35"} );
      CHECK_THROWS( Time{"24:35:35"} );
      CHECK_THROWS( Time{"2e:35:35"} );
      CHECK_THROWS( Time{"23-35:35"} );
      CHECK_THROWS( Time{"23:3e:35"} );
      CHECK_THROWS( Time{"23:35-35"} );
      CHECK_THROWS( Time{"23:35:3e"} );
      CHECK_THROWS( Time{"23:59:59e"});

      CHECK( t0.get_hour()   == 0 );
      CHECK( t0.get_minute() == 0 );
      CHECK( t0.get_second() == 0 );
      CHECK( t1.get_hour()   == 12 );
      CHECK( t1.get_minute() == 30 );
      CHECK( t1.get_second() == 30 );
      CHECK( t2.get_hour()   == 23 );
      CHECK( t2.get_minute() == 59 );
      CHECK( t2.get_second() == 59 );  
   }
}

TEST_CASE ("is_am") 
{
   Time t0{"05:00:00"};
   Time t1{"14:00:00"};
   Time t2{"00:00:00"};
   Time t3{"12:00:00"};
   CHECK       ( t0.is_am() );
   CHECK_FALSE ( t1.is_am() );
   CHECK       (t2.is_am() );
   CHECK_FALSE (t3.is_am() );
   // Fill with extra corner cases! ¯\_(ツ)_/¯
}

TEST_CASE ("to_string")
{
   Time t0{};
   Time t1{11, 59, 59};
   Time t2{12, 0, 0};
   Time t3{13, 0, 0};
   Time t4{23, 59, 59};
   SECTION("24 hour format no argument")
   {
      CHECK( t0.to_string() == "00:00:00" );
      CHECK_FALSE(t0.to_string() != "00:00:00");
   }
   
   SECTION("24 hour format with argument")
   {
      CHECK (t1.to_string() == "11:59:59" );
      CHECK (t2.to_string() == "12:00:00");
      CHECK (t3.to_string() == "13:00:00");
      CHECK (t4.to_string() == "23:59:59");
   } 

   SECTION("12 hour format")
   {
      CHECK (t0.to_string(1) == "12:00:00am");
      CHECK (t1.to_string(1) == "11:59:59am");
      CHECK (t2.to_string(1) == "12:00:00pm");
      CHECK (t3.to_string(1) == "01:00:00pm");
      CHECK (t4.to_string(1) == "11:59:59pm");
   }
}

// Fill with more tests of other functions and operators!
TEST_CASE("addition operators")
{
   SECTION("obj + int")
   {
      Time t0{"00:00:00"};
      Time t1 = t0 + 1;
      Time t2 = t0 + (-1);
      Time t3 = t0 + 60;
      Time t4 = t0 + (-60);
      Time t5 = t0 + 90000;
      Time t6 = t0 + (-90000);
      CHECK (t1.to_string() == "00:00:01" );
      CHECK (t2.to_string() == "23:59:59" );
      CHECK (t3.to_string() == "00:01:00");
      CHECK (t4.to_string() == "23:59:00");
      CHECK (t5.to_string() == "01:00:00");
      CHECK (t6.to_string() == "23:00:00");
   }
   SECTION("int + obj")
   {
      Time t0{"00:00:00"};
      Time t1 = 1 + t0; 
      Time t2 = (-1) + t0; 
      Time t3 = 60 + t0; 
      Time t4 = (-60) + t0; 
      Time t5 = 90000 + t0; 
      Time t6 = (-90000) + t0; 
      CHECK (t1.to_string() == "00:00:01");
      CHECK (t2.to_string() == "23:59:59");
      CHECK (t3.to_string() == "00:01:00");
      CHECK (t4.to_string() == "23:59:00");
      CHECK (t5.to_string() == "01:00:00");
      CHECK (t6.to_string() == "23:00:00");
   }
}

TEST_CASE("Subtraction operators")
{
   SECTION("obj - int")
   {
      Time t0{"00:00:00"};
      Time t1 = t0 - 1;
      Time t2 = t0 - (-1);
      Time t3 = t0 - 60;
      Time t4 = t0 - (-60);
      Time t5 = t0 - 90000;
      Time t6 = t0 - (-90000);
      CHECK (t1.to_string() == "23:59:59" );
      CHECK (t2.to_string() == "00:00:01");
      CHECK (t3.to_string() == "23:59:00");
      CHECK (t4.to_string() == "00:01:00");
      CHECK (t5.to_string() == "23:00:00");
      CHECK (t6.to_string() == "01:00:00");
   }

   SECTION("int - obj ")
   {
      Time t0{"12:00:00"};
      Time t1 = 1  - t0; 
      Time t2 = (-1)  - t0; 
      Time t3 = 60  - t0; 
      Time t4 = (-60)  - t0; 
      Time t5 = 136400  - t0; 
      Time t6 = (-90000)  - t0; 
      CHECK (t1.to_string() == "12:00:01" );
      CHECK (t2.to_string() == "11:59:59");
      CHECK (t3.to_string() == "12:01:00");
      CHECK (t4.to_string() == "11:59:00");
      CHECK (t5.to_string() == "01:53:20");
      CHECK (t6.to_string() == "11:00:00");
   }
}

TEST_CASE("increment & decrement operators")
{
   SECTION("increment prefix")
   {
      Time t0{};
      Time t1 = ++t0;
      Time t2 = ++ ++t0;
      Time t3{"23:59:59"};
      ++t3;
      CHECK(t0.to_string() == "00:00:03");
      CHECK(t1.to_string() == "00:00:01");
      CHECK(t2.to_string() == "00:00:03");
      CHECK(t3.to_string() == "00:00:00");
   }

   SECTION("increment postfix")
   {
      Time t0{};
      Time t1 = t0++;
      Time t2{"23:59:59"};
      t2++;
      CHECK(t0.to_string() == "00:00:01");
      CHECK(t1.to_string() == "00:00:00");
      CHECK(t2.to_string() == "00:00:00");
   }

   SECTION("decrement prefix")
   {
      Time t0{};
      Time t1 = --t0;
      Time t2 = -- --t0;
      CHECK(t0.to_string() == "23:59:57");
      CHECK(t1.to_string() == "23:59:59");
      CHECK(t2.to_string() == "23:59:57");
   }

   SECTION("decrement postfix")
   {
      Time t0{};
      Time t1 = t0--;
      CHECK(t0.to_string() == "23:59:59");
      CHECK(t1.to_string() == "00:00:00");
   }
}