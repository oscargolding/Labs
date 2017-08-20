// localTime.c
// A program to test a function getLocalTime which determines the
// local time in a specified city, given the current UTC time.
//
// This program by Oscar Golding (z5160173) on 2017-08-1
//
// Program stub created by Andrew Bennett on 2017-08-01.
// Version 1.0.4: Fix incorrect Lord Howe Island unit test.
// Version 1.0.3: Add version numbers.
// Version 1.0.2: Fixed include order.
// Version 1.0.1: Fix `CITY_LORD_HOWE_IS` symbol name.
// Version 1.0.0: First release onto an unsuspecting class.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE !TRUE

// ===========      Cities      ===========

// Australia
#define CITY_PERTH          0
#define CITY_EUCLA          1
#define CITY_ADELAIDE       2
#define CITY_DARWIN         3
#define CITY_BROKEN_HILL    4
#define CITY_HOBART         5
#define CITY_SYDNEY         6
#define CITY_CANBERRA       7
#define CITY_MELBOURNE      8
#define CITY_BRISBANE       9
#define CITY_LORD_HOWE_IS   10

// New-Zealand
#define CITY_AUCKLAND       11
#define CITY_CHRISTCHURCH   12
#define CITY_WELLINGTON     13

/* #define CITY_ADELAIDE       0
#define CITY_BRISBANE       1
#define CITY_BROKEN_HILL    2
#define CITY_CANBERRA       3
#define CITY_DARWIN         4
#define CITY_EUCLA          5
#define CITY_HOBART         6
#define CITY_LORD_HOWE_IS   7
#define CITY_MELBOURNE      8
#define CITY_PERTH          9
#define CITY_SYDNEY         10

// New Zealand
#define CITY_AUCKLAND       11
#define CITY_CHRISTCHURCH   12
#define CITY_WELLINGTON     13 */

// =========== Timezone Offsets ===========

// Australia
#define TIMEZONE_AWST  800 // Australian Western Standard Time

#define TIMEZONE_ACWST 845 // Australian Central Western Standard Time

#define TIMEZONE_ACST  930 // Australian Central Standard Time
#define TIMEZONE_ACDT 1030 // Australian Central Daylight Time

#define TIMEZONE_AEST 1000 // Australian Eastern Standard Time
#define TIMEZONE_AEDT 1100 // Australian Eastern Daylight Time

#define TIMEZONE_LHST 1030 // Lord Howe Standard Time
#define TIMEZONE_LHDR 1100 // Lord Howe Daylight Time

// New Zealand
#define TIMEZONE_NZST 1200 // NZ Standard Time
#define TIMEZONE_NZDT 1300 // NZ Daylight Time


// =========== Function Prototypes ===========
//       [DO NOT CHANGE THIS PROTOTYPE!]
int getLocalTime (int city, int day, int month, int timeUTC);
int basicConversion (int city, int timeUTC);
int AWSTC (int timeUTC);
int ACWST (int timeUTC);
int ACST (int timeUTC);
int AEST (int timeUTC);
int LHST (int timeUTC);
int NZST (int timeUTC);
int check (int tim);
int check1 (int tim);
int getRealTime (int city, int day, int month, int localTime, int timeUTC);
int conversionDST1 (int localTime);
int conversionDST2 (int localTime);
int AUSDST (int city, int day, int month, int localTime, int timeUTC);
int LHIDST (int city, int day, int month, int localTime, int timeUTC);
int NZDST (int city, int day, int month, int localTime, int timeUTC);

int main (int argc, char *argv[]) {

    assert(getLocalTime(CITY_PERTH, 2, 5, 2000) == 400);

    assert(getLocalTime(CITY_SYDNEY, 5, 4, 0) == 1000);

    // UTC time: 8:59am on 15th May, time in Christchurch: 8:59pm
    assert(getLocalTime(CITY_CHRISTCHURCH, 15, 5, 859) == 2059);

    // UTC time: midnight on 5th April, time in Sydney: 10am
    assert(getLocalTime(CITY_SYDNEY, 5, 4, 0) == 1000);

    // UTC time: 10:30am on 30th June, time in Adelaide: 8pm
    assert(getLocalTime(CITY_ADELAIDE, 30, 6, 1030) == 2000);

    // UTC time: 8:15pm on 17th August, time in Brisane: 6:15am
    assert(getLocalTime(CITY_BRISBANE, 17, 8, 2015) == 615);

    // UTC time: 8am on 27th April, time in Auckland: 8pm
    assert(getLocalTime(CITY_AUCKLAND, 27, 4, 800) == 2000);

    // UTC time: 11:11pm on 30th January, time in Perth: 7:11am on the 31st
    assert(getLocalTime(CITY_PERTH, 30, 1, 2311) == 711);

    // UTC time: 8pm on 5th May, time in Perth: 4am on the 6th
    assert(getLocalTime(CITY_PERTH, 2, 5, 2000) == 400);

    // UTC time: 10:30pm on 6th Oct, time in Christchurch: 11:30am on the 7th
    assert(getLocalTime(CITY_CHRISTCHURCH, 6, 10, 2230) == 1130);

    // UTC time: 2:28pm on 16th December, time in Canberra: 1:28am on the 17th
    assert(getLocalTime(CITY_CANBERRA, 16, 12, 1428) == 128);

    // UTC time: 3:39am on 1st November, time in Darwin: 1:09pm
    assert(getLocalTime(CITY_DARWIN, 1, 11, 339) == 1309);

    // UTC time: 1pm on 8th July, time in Hobart: 11pm
    assert(getLocalTime(CITY_HOBART, 8, 7, 1300) == 2300);

    // UTC time: 1:54pm on 27th September, time in Melbourne: 11:54pm
    assert(getLocalTime(CITY_MELBOURNE, 27, 9, 1354) == 2354);

    // UTC time: 9:24am on 5th January, time in Wellington: 10:24pm
    assert(getLocalTime(CITY_WELLINGTON, 5, 1, 924) == 2224);

    // UTC time: 2pm on 18th April, time in Brisbane: 12:00am on the 19th
    assert(getLocalTime(CITY_BRISBANE, 18, 4, 1400) == 0);

    // UTC time: 11:06am on 8th October, time in Brisbane: 9:06pm
    assert(getLocalTime(CITY_BRISBANE, 8, 10, 1106) == 2106);

    // UTC time: 12:01pm on 29th October, time in Sydney: 11:01pm
    assert(getLocalTime(CITY_SYDNEY, 29, 10, 1201) == 2301);

    // UTC time: 11:45pm on 17th February, time in Darwin: 9:15am on the 18th
    assert(getLocalTime(CITY_DARWIN, 17, 2, 2345) == 915);

    // UTC time: 11pm on 7th August, time in Auckland: 10am on the 8th
    assert(getLocalTime(CITY_AUCKLAND, 7, 8, 2200) == 1000);

    // UTC time: 10:15 am on 5th September, time in Eucla: 7pm
    assert(getLocalTime(CITY_EUCLA, 5, 9, 1015) == 1900);

    // UTC time: 10am on 1st January, time in Broken Hill: 8:30pm
    assert(getLocalTime(CITY_BROKEN_HILL, 1, 1, 1000) == 2030);

    // UTC time: 10:15pm on 1st October, time in Lord Howe Island: 9:15am on the 2nd
    assert(getLocalTime(CITY_LORD_HOWE_IS, 1, 10, 2215) == 915);

    // UTC time: 11:59pm on 6th February, time in Eucla: 8:44am on the 7th
    assert(getLocalTime(CITY_EUCLA, 6, 2, 2359) == 844);

    // UTC time: 1:17am on 17th July, time in Broken Hill: 10:47 am
    assert(getLocalTime(CITY_BROKEN_HILL, 17, 7, 117) == 1047);

    assert(getLocalTime(CITY_EUCLA, 6, 2, 855) == 1740);

    assert(getLocalTime(CITY_WELLINGTON, 24, 12, 1100) == 0);

    assert(getLocalTime(CITY_BROKEN_HILL, 24, 12, 1330) == 0);

    assert(getLocalTime(CITY_MELBOURNE, 24, 12, 1300) == 0);

    assert(getLocalTime(CITY_AUCKLAND, 23, 9, 1359) == 159);

    //UTC time: 2:00 pm on 23rd September, time in Auckland: 3:00am
    assert(getLocalTime(CITY_AUCKLAND, 23, 9, 1400) == 300);

    // UTC time: 2:00 pm on 1st April, time in Auckland: 2:00am
    assert(getLocalTime(CITY_AUCKLAND, 1, 4, 1400) == 200);

    // UTC time: 1:59 pm on 1st April, time in Auckland: 2:59am
    assert(getLocalTime(CITY_AUCKLAND, 1, 4, 1359) == 259);

    // UTC time: 2:00 pm on 1st April, time in Auckland: 2:00am
    assert(getLocalTime(CITY_AUCKLAND, 1, 4, 1400) == 200);

    //UTC time: 3:59 pm on 30th September, time in Canberra: 1:59am
    assert(getLocalTime(CITY_CANBERRA, 30, 9, 1559) == 159);

    //UTC time: 4:00 pm on 30th September, time in Canberra: 3:00am
    assert(getLocalTime(CITY_CANBERRA, 30, 9, 1600) == 300);

    // UTC time: 3:59 pm on 1st April, time in Canberra: 2:59am
    assert(getLocalTime(CITY_CANBERRA, 1, 4, 1559) == 259);

    // UTC time: 4:00 pm on 1st April, time in Canberra: 2:00am
    assert(getLocalTime(CITY_CANBERRA, 1, 4, 1600) == 200);

    //UTC time: 4:29 pm on 30th September, time in Adelaide: 1:59am
    assert(getLocalTime(CITY_ADELAIDE, 30, 9, 1629) == 159);
    //UTC time: 4:30 pm on 30th September, time in Adelaide: 3:00am

    assert(getLocalTime(CITY_ADELAIDE, 30, 9, 1630) == 300);

    // UTC time: 4:29 pm on 1st April, time in Adelaide: 2:59am
    assert(getLocalTime(CITY_ADELAIDE, 1, 4, 1629) == 259);

    // UTC time: 4:30 pm on 1st April, time in Adelaide: 2:00am
    assert(getLocalTime(CITY_ADELAIDE, 1, 4, 1630) == 200);

    //UTC time: 3:29 pm on 30th September, time in Lord Howe Island: 1:59am
    assert(getLocalTime(CITY_LORD_HOWE_IS, 30, 9, 1529) == 159);

    //UTC time: 3:30 pm on 30th September, time in Lord Howe Island: 2:30am
    assert(getLocalTime(CITY_LORD_HOWE_IS, 30, 9, 1530) == 230);

    // UTC time: 2:59 pm on 1st April, time in Lord Howe Island: 1:59am
    assert(getLocalTime(CITY_LORD_HOWE_IS, 1, 4, 1459) == 159);

    assert(getLocalTime(CITY_LORD_HOWE_IS, 1, 5, 1500) == 130);

    assert(getLocalTime(CITY_LORD_HOWE_IS, 1, 4, 1900) == 530);

    // UTC time: 3:00 pm on 1st April, time in Lord Howe Island: 1:30am
    assert(getLocalTime(CITY_LORD_HOWE_IS, 1, 4, 1500) == 130);

    //UTC time: 8:20pm on 1st January, time in Western Austrlia: 4:20am
    assert(getLocalTime(CITY_PERTH, 1, 1, 2020) == 420);

    assert(getLocalTime(CITY_WELLINGTON, 23, 9, 1400) == 300);

    // UTC time: 3:59pm on 30th September, time in Sydney: 1:59am
    assert(getLocalTime(CITY_SYDNEY, 30, 9, 1559) == 159);

    // UTC time: 4:00pm on 30th September, time in Sydney: 3:00am

    assert(getLocalTime(CITY_SYDNEY, 30, 9, 1600) == 300);

    // UTC time: 5:00pm on 30th September, time in Sydney: 4:00am
    assert(getLocalTime(CITY_SYDNEY, 30, 9, 1700) == 400);

    // UTC time: 5:00pm on 1st October, time in Sydney: 4:00am
    assert(getLocalTime(CITY_SYDNEY, 1, 10, 1700) == 400);

    assert(getLocalTime(CITY_CANBERRA, 6, 6, 356) == 1356);

    // UTC time: 3:30pm on 1st April, time in Melbourne: 2:30 am on the 2nd
    assert(getLocalTime(CITY_MELBOURNE, 1, 4, 1530) == 230);

    // UTC time: 4:30pm on 1st April, time in Melbourne: 2:30 am on the 2nd
    assert(getLocalTime(CITY_MELBOURNE, 1, 4, 1630) == 230);

    // UTC time: 3:59pm on 30th September, time in Sydney: 1:59 am on October 1st
    assert(getLocalTime(CITY_SYDNEY, 30, 9, 1559) == 159);

    // UTC time: 4:00pm on 30th September, time in Sydney: 3:00 am on October 1st
    assert(getLocalTime(CITY_SYDNEY, 30, 9, 1600) == 300);

    // UTC time: 2:59 pm on 1st April, time in Lord Howe Island: 1:59am
    assert(getLocalTime(CITY_LORD_HOWE_IS, 1, 4, 1459) == 159);
    // UTC time: 3:00 pm on 1st April, time in Lord Howe Island: 1:30am
    assert(getLocalTime(CITY_LORD_HOWE_IS, 1, 4, 1500) == 130);

    //UTC time: 3:29 pm on 30th September, time in Lord Howe Island: 1:59am
    assert(getLocalTime(CITY_LORD_HOWE_IS, 30, 9, 1529) == 159);
    // UTC time: 3:30 pm on 30th September, time in Lord Howe Island: 2:30am
    assert(getLocalTime(CITY_LORD_HOWE_IS, 30, 9, 1530) == 230);

    assert(getLocalTime(CITY_MELBOURNE, 24, 12, 1300) == 0);

    // UTC time: 1:30pm on 24th December, time in Broken Hill: midnight
    assert(getLocalTime(CITY_BROKEN_HILL, 24, 12, 1330) == 0);

    // UTC time: 11:00am on 24th December, time in Wellington: midnight
    assert(getLocalTime(CITY_WELLINGTON, 24, 12, 1100) == 0);

    assert(getLocalTime(CITY_LORD_HOWE_IS, 1, 4, 1430) == 130);

    assert(getLocalTime(CITY_LORD_HOWE_IS, 2, 1, 830) == 1930);

    assert(getLocalTime(CITY_LORD_HOWE_IS, 1, 4, 830) == 1930);

    assert(getLocalTime(CITY_WELLINGTON, 23, 9, 830) == 2030);

    assert(getLocalTime(CITY_SYDNEY, 30, 9, 730) == 1730);

    assert(getLocalTime(CITY_SYDNEY, 23, 9, 2230) == 830);

    assert(getLocalTime(CITY_SYDNEY, 30, 9, 2230) == 930);

    assert(getLocalTime(CITY_LORD_HOWE_IS, 30, 9, 2230) == 930);

    assert(getLocalTime(CITY_WELLINGTON, 30, 9, 2230) == 1130);

    // UTC time: 8:02pm on 22nd Septemer, time in Eucla: 4:47am on the 23rd
    assert(getLocalTime(CITY_EUCLA, 22, 9, 2002) == 447);

    // UTC time: 10:28am on 20th March, time in Eucla: 7:13pm
    assert(getLocalTime(CITY_EUCLA, 20, 3, 1028) == 1913);

    // UTC time: 7:57am on 24th September, time in Broken Hill: 5:27pm
    assert(getLocalTime(CITY_BROKEN_HILL, 24, 9, 757) == 1727);

    //UTC time: 11:30am on 30th October, time in Sydney: 10:30pm
    assert(getLocalTime(CITY_SYDNEY, 30, 10, 1130) == 2230);

    // UTC time: 11:00pm on 25th May, time in Perth: 7am on the 26th
    assert(getLocalTime(CITY_PERTH, 25, 5, 2300) == 700);

    // UTC time: 1:59pm on Sunday 27th August; time in Sydney: 11:59pm
    assert(getLocalTime(CITY_SYDNEY, 27, 8, 1359) == 2359);

    assert(getLocalTime(CITY_AUCKLAND, 26, 9, 300) == 1600);

    assert(getLocalTime(CITY_EUCLA, 1, 4, 1555) == 40);

    // UTC time: 5:36am on 24th October, time in Adelaide: 4:06pm
    assert(getLocalTime(CITY_ADELAIDE, 24, 10, 536) == 1606);

    //UTC time: 4:00 pm on 30th September, time in Canberra: 3:00am
    assert(getLocalTime(CITY_CANBERRA, 30, 9, 1600) == 300);

    // UTC time: 4:30pm on 30th September, time in Adelaide: 3:00am on 1st October
    assert(getLocalTime(CITY_ADELAIDE, 30, 9, 1630) == 300);

    // UTC time: 5:00pm on 30th September, time in Sydney: 4:00am on 1st October
    assert(getLocalTime(CITY_SYDNEY, 30, 9, 1700) == 400);

    // UTC time: 3:40pm on 30th September, time in Melbourne: 1:40am on 1st October
    assert(getLocalTime(CITY_MELBOURNE, 30, 9, 1540) == 140);

    // UTC time: 4:20pm on 1st April, time in Adelaide: 2:50am on 2st April
    assert(getLocalTime(CITY_ADELAIDE, 1, 4, 1620) == 250);

    // UTC time: 4:20pm on 1st April, time in Sydney: 1:50am on 1st April
    assert(getLocalTime(CITY_SYDNEY, 1, 4, 1620) == 220);

    assert(getLocalTime(CITY_EUCLA, 19, 9, 2006) == 451);

    // UTC time: 0:59am on 2nd April, time in Eucla: 9:44am
    assert(getLocalTime(CITY_EUCLA, 2, 4, 59) == 944);

    // UTC time: 3:00pm on 2nd April, time in LORD_HOWE_IS: 1:30am
    assert(getLocalTime(CITY_LORD_HOWE_IS, 2, 4, 1500) == 130);

    assert(getLocalTime(CITY_DARWIN, 30, 5, 17) == 947);

    //UTC time: 3:29 pm on 30th September, time in Lord Howe Island: 1:59am
    assert(getLocalTime(CITY_LORD_HOWE_IS, 30, 9, 1529) == 159);

    //UTC time: 3:30 pm on 30th September, time in Lord Howe Island: 2:30am
    assert(getLocalTime(CITY_LORD_HOWE_IS, 30, 9, 1530) == 230);

    // UTC time: 2:59 pm on 1st April, time in Lord Howe Island: 1:59am
    assert(getLocalTime(CITY_LORD_HOWE_IS, 1, 4, 1459) == 159);

    // UTC time: 3:00 pm on 1st April, time in Lord Howe Island: 1:30am
    assert(getLocalTime(CITY_LORD_HOWE_IS, 1, 4, 1500) == 130);

    //UTC time: 1:59 pm on 23rd September, time in Auckland: 1:59am
    assert(getLocalTime(CITY_AUCKLAND, 23, 9, 1359) == 159);

    //UTC time: 2:00 pm on 23rd September, time in Auckland: 3:00am
    assert(getLocalTime(CITY_AUCKLAND, 23, 9, 1400) == 300);

    // UTC time: 1:59 pm on 1st April, time in Auckland: 2:59am
    assert(getLocalTime(CITY_AUCKLAND, 1, 4, 1359) == 259);

    // UTC time: 2:00 pm on 1st April, time in Auckland: 2:00am
    assert(getLocalTime(CITY_AUCKLAND, 1, 4, 1400) == 200);

    //UTC time: 3:59 pm on 30th September, time in Canberra: 1:59am
    assert(getLocalTime(CITY_CANBERRA, 30, 9, 1559) == 159);

    //UTC time: 4:00 pm on 30th September, time in Canberra: 3:00am
    assert(getLocalTime(CITY_CANBERRA, 30, 9, 1600) == 300);

    // UTC time: 3:59 pm on 1st April, time in Canberra: 2:59am
    assert(getLocalTime(CITY_CANBERRA, 1, 4, 1559) == 259);

    // UTC time: 4:00 pm on 1st April, time in Canberra: 2:00am
    assert(getLocalTime(CITY_CANBERRA, 1, 4, 1600) == 200);

    // UTC time: 3:59pm on 30th September, time in Sydney: 1:59am
    assert(getLocalTime(CITY_SYDNEY, 30, 9, 1559) == 159);

    // UTC time: 4:00pm on 30th September, time in Sydney: 3:00am
    assert(getLocalTime(CITY_SYDNEY, 30, 9, 1600) == 300);

    // UTC time: 5:00pm on 30th September, time in Sydney: 4:00am
    assert(getLocalTime(CITY_SYDNEY, 30, 9, 1700) == 400);

    // UTC time: 5:00pm on 1st October, time in Sydney: 4:00am
    assert(getLocalTime(CITY_SYDNEY, 1, 10, 1700) == 400);

    assert(getLocalTime(CITY_WELLINGTON, 5, 2, 1826) == 726);

    assert(getLocalTime(CITY_WELLINGTON, 1, 3, 426) == 1726);







    // Add your own tests here

    return EXIT_SUCCESS;

}


// Converts the time to local time
// [DO NOT CHANGE THIS PROTOTYPE!]
int getLocalTime (int city, int day, int month, int timeUTC) {

    // REPLACE THIS WITH YOUR OWN CODE
    int localTime = basicConversion(city, timeUTC);
    printf("The local time is %d\n", localTime);
    // INSERT YOUR OWN CODE HERE
    int realTime = getRealTime(city, day, month, localTime, timeUTC);
    printf("The real time is %d\n", realTime);

    return realTime;
}
int basicConversion (int city, int timeUTC) {
    int a;
    if (city == CITY_PERTH) {
        a = AWSTC(timeUTC);
        return a;
    } else if (city == CITY_EUCLA) {
        a = ACWST(timeUTC);
        return a;
    } else if (city >= CITY_ADELAIDE && city <= CITY_BROKEN_HILL) {
        a = ACST(timeUTC);
        return a;
    } else if (city >= CITY_HOBART && city <= CITY_BRISBANE) {
        a = AEST(timeUTC);
        return a;
    } else if (city == CITY_LORD_HOWE_IS) {
        a = LHST(timeUTC);
        return a;
    } else {
        a = NZST(timeUTC);
        return a;
    }
}
int AWSTC (int timeUTC) {
    int tim;
    int a;
    int b;
    tim = timeUTC + TIMEZONE_AWST;
    if (tim >= 2400) {
        a = tim - 2400;
        b = check(a);
        return b;
    } else {
        b = check(tim);
        return b;
    }
}
int ACWST (int timeUTC) {
    int tim;
    int a;
    int c;
    int d;
    tim = timeUTC + TIMEZONE_ACWST;
    if (tim >= 2400) {
        a = tim - 2400;
        c = check1(a);
        d = check(c);
        return d;
    } else {
        c = check1(tim);
        d = check(c);
        return d;
    }
}
int ACST (int timeUTC) {
    int tim;
    int a;
    int b;
    tim = timeUTC + TIMEZONE_ACST;
    if (tim >= 2400) {
        a = tim - 2400;
        b = check(a);
        return b;
    } else {
        b = check(tim);
        return b;
    }
}
int AEST (int timeUTC) {
    int tim;
    int a;
    int b;
    tim = timeUTC + TIMEZONE_AEST;
    if (tim >= 2400) {
        a = tim - 2400;
        b = check(a);
        return b;
    } else {
        b = check(tim);
        return b;
    }
}
int LHST (int timeUTC) {
    int tim;
    int a;
    int b;
    tim = timeUTC + TIMEZONE_LHST;
    if (tim >= 2400) {
        a = tim - 2400;
        b = check(a);
        return b;
    } else {
        b = check(tim);
        return b;
    }
}
int NZST (int timeUTC) {
    int tim;
    int a;
    int b;
    tim = timeUTC + TIMEZONE_NZST;
    if (tim >= 2400) {
        a = tim - 2400;
        b = check(a);
        return b;
    } else {
        b = check(tim);
        return b;
    }
}
int check (int tim) {
    if (tim >= 60 && tim < 100) {
        int b;
        b = tim - 60 + 100;
        return b;
    } else if (tim >= 160 && tim < 200) {
        int b;
        b = tim - 60 + 100;
        return b;
    } else if (tim >= 260 && tim < 300) {
        int b;
        b = tim - 60 + 100;
        return b;
    } else if (tim >= 360 && tim < 400) {
        int b;
        b = tim - 60 + 100;
        return b;
    } else if (tim >= 460 && tim < 500) {
        int b;
        b = tim - 60 + 100;
        return b;
    } else if (tim >= 560 && tim < 600) {
        int b;
        b = tim - 60 + 100;
        return b;
    } else if (tim >= 660 && tim < 700) {
        int b;
        b = tim - 60 + 100;
        return b;
    } else if (tim >= 760 && tim < 800) {
        int b;
        b = tim - 60 + 100;
        return b;
    } else if (tim >= 860 && tim < 900) {
        int b;
        b = tim - 60 + 100;
        return b;
    } else if (tim >= 960 && tim < 1000) {
        int b;
        b = tim - 60 + 100;
        return b;
    } else if (tim >= 1060 && tim < 1100) {
        int b;
        b = tim - 60 + 100;
        return b;
    } else if (tim >= 1160 && tim < 1200) {
        int b;
        b = tim - 60 + 100;
        return b;
    } else if (tim >= 1260 && tim < 1300) {
        int b;
        b = tim - 60 + 100;
        return b;
    } else if (tim >= 1360 && tim < 1400) {
        int b;
        b = tim - 60 + 100;
        return b;
    } else if (tim >= 1460 && tim < 1500) {
        int b;
        b = tim - 60 + 100;
        return b;
    } else if (tim >= 1560 && tim < 1600) {
        int b;
        b = tim - 60 + 100;
        return b;
    } else if (tim >= 1660 && tim < 1700) {
        int b;
        b = tim - 60 + 100;
        return b;
    } else if (tim >= 1760 && tim < 1800) {
        int b;
        b = tim - 60 + 100;
        return b;
    } else if (tim >= 1860 && tim < 1900) {
        int b;
        b = tim - 60 + 100;
        return b;
    } else if (tim >= 1960 && tim < 2000) {
        int b;
        b = tim - 60 + 100;
        return b;
    } else if (tim >= 2060 && tim < 2100) {
        int b;
        b = tim - 60 + 100;
        return b;
    } else if (tim >= 2160 && tim < 2200) {
        int b;
        b = tim - 60 + 100;
        return b;
    } else if (tim >= 2260 && tim < 2300) {
        int b;
        b = tim - 60 + 100;
        return b;
    } else if (tim >= 2360 && tim < 2400) {
        int b;
        b = tim - 60 + 100;
        return b;
    } else {
        return tim;
    }
}
int check1 (int tim) {
    if (tim >= 0 && tim < 5) {
        int b;
        b = tim + 40;
        return b;
    } else if (tim >= 100 && tim < 105) {
        int b;
        b = tim + 40;
        return b;
    } else if (tim >= 200 && tim < 205) {
        int b;
        b = tim + 40;
        return b;
    } else if (tim >= 300 && tim < 305) {
        int b;
        b = tim + 40;
        return b;
    } else if (tim >= 400 && tim < 405) {
        int b;
        b = tim + 40;
        return b;
    } else if (tim >= 500 && tim < 505) {
        int b;
        b = tim + 40;
        return b;
    } else if (tim >= 600 && tim < 605) {
        int b;
        b = tim + 40;
        return b;
    } else if (tim >= 700 && tim < 705) {
        int b;
        b = tim + 40;
        return b;
    } else if (tim >= 800 && tim < 805) {
        int b;
        b = tim + 40;
        return b;
    } else if (tim >= 900 && tim < 905) {
        int b;
        b = tim + 40;
        return b;
    } else if (tim >= 1000 && tim < 1005) {
        int b;
        b = tim + 40;
        return b;
    } else if (tim >= 1100 && tim < 1105) {
        int b;
        b = tim + 40;
        return b;
    } else if (tim >= 1200 && tim < 1205) {
        int b;
        b = tim + 40;
        return b;
    } else if (tim >= 1300 && tim < 1305) {
        int b;
        b = tim + 40;
        return b;
    } else if (tim >= 1400 && tim < 1405) {
        int b;
        b = tim + 40;
        return b;
    } else if (tim >= 1500 && tim < 1505) {
        int b;
        b = tim + 40;
        return b;
    } else if (tim >= 1600 && tim < 1605) {
        int b;
        b = tim + 40;
        return b;
    } else if (tim >= 1700 && tim < 1705) {
        int b;
        b = tim + 40;
        return b;
    } else if (tim >= 1800 && tim < 1805) {
        int b;
        b = tim + 40;
        return b;
    } else if (tim >= 1900 && tim < 1905) {
        int b;
        b = tim + 40;
        return b;
    } else if (tim >= 2000 && tim < 2005) {
        int b;
        b = tim + 40;
        return b;
    } else if (tim >= 2100 && tim < 2105) {
        int b;
        b = tim + 40;
        return b;
    } else if (tim >= 2200 && tim < 2205) {
        int b;
        b = tim + 40;
        return b;
    } else if (tim >= 2300 && tim < 2305) {
        int b;
        b = tim + 40;
        return b;
    } else {
        return tim;
    }
}
int getRealTime (int city, int day, int month, int localTime, int timeUTC) {
    if (city == CITY_PERTH || city == CITY_EUCLA || city == CITY_DARWIN || city == CITY_BRISBANE) {
        return localTime;
    // Branch for Australian Cities.
    } else if (city == CITY_ADELAIDE || city == CITY_BROKEN_HILL || city == CITY_HOBART || city == CITY_SYDNEY || city == CITY_CANBERRA || city == CITY_MELBOURNE) {
        int a = AUSDST(city, day, month, localTime, timeUTC);
        return a;
    // Branch for Lorde Howe Island
    } else if (city == CITY_LORD_HOWE_IS) {
        int a = LHIDST(city, day, month, localTime, timeUTC);
        return a;
    // NZ Branch
    } else if (city == CITY_AUCKLAND || city == CITY_CHRISTCHURCH || city == CITY_WELLINGTON) {
        int a = NZDST(city, day, month, localTime, timeUTC);
        return a;
    } else {
        return localTime;
    }
}
int conversionDST1 (int localTime) {
    int a;
    a = 100 + localTime;
    if (a >= 2400) {
        int b;
        b = a - 2400;
        return b;
    } else {
        return a;
    }
}
int conversionDST2 (int localTime) {
    int a;
    a = 30 + localTime;
    if (a >= 2400) {
        int b;
        b = a - 2400;
        int c;
        c = check(b);
        return c;
    } else {
        int b;
        b = check(a);
        return b;
    }
}
int AUSDST (int city, int day, int month, int localTime, int timeUTC) {
    if (month > 4 && month < 9) {
        return localTime;
    } else if (month < 4 || month > 10) {
        int a;
        a = conversionDST1(localTime);
        return a;
    } else if (month == 4) {
        if (day > 2) {
            return localTime;
        } else if (day == 1){
            if (timeUTC > 1400) {
                if (localTime == 200 || localTime > 200) {
                    return localTime;
                } else {
                    int a;
                    a = conversionDST1(localTime);
                    return a;
                }
            } else {
                int a;
                a = conversionDST1(localTime);
                return a;
            }
        } else if (day == 2) {
            if (localTime < 200) {
                int a;
                a = conversionDST1(localTime);
                return a;
            } else if (localTime == 200 || localTime > 200) {
                return localTime;
            } else {
                return localTime;
            }
        } else {
            return localTime;
        }
    } else if (month == 10) {
        if (day < 1) {
            return localTime;
        } else if (day > 2){
            int a;
            a = conversionDST1(localTime);
            return a;
        } else if (day == 1) {
            if (localTime < 200) {
                return localTime;
            } else if (localTime == 200 || localTime > 200) {
                int a;
                a = conversionDST1(localTime);
                return a;
            } else {
                return localTime;
            }
        } else {
            return localTime;
        }
    } else if (month == 9){
        if (day < 30) {
            return localTime;
        } else if (day == 30){
            if (timeUTC > 1400) {
                if (localTime == 200 || localTime > 200) {
                    int a;
                    a = conversionDST1(localTime);
                    return a;
                } else {
                    return localTime;
                }
            } else {
                return localTime;
            }
        } else {
            return localTime;
        }
    } else {
        return localTime;
    }
}
int LHIDST (int city, int day, int month, int localTime, int timeUTC) {
    if (month > 4 && month < 9) {
        return localTime;
    } else if (month < 4 || month > 10) {
        int a;
        a = conversionDST2(localTime);
        return a;
    } else if (month == 4) {
        if (day > 2) {
            return localTime;
        } else if (day == 1) {
            if (timeUTC > 1200) {
                if (localTime == 130 || localTime > 130) {
                    return localTime;
                } else {
                    int a;
                    a = conversionDST2(localTime);
                    return a;
                }
            } else {
                int a;
                a = conversionDST2(localTime);
                return a;
            }
        } else if (day == 2) {
            if (localTime < 130) {
                int a;
                a = conversionDST2(localTime);
                return a;
            } else if (localTime == 130 || localTime > 130) {
                return localTime;
            } else {
                return localTime;
            }
        } else {
            return localTime;
        }
    } else if (month == 10) {
        if (day < 1) {
            return localTime;
        } else if (day > 2){
            int a;
            a = conversionDST2(localTime);
            return a;
        } else if (day == 1) {
            if (localTime < 200) {
                return localTime;
            } else if (localTime == 200 || localTime > 200) {
                int a;
                a = conversionDST2(localTime);
                return a;
            } else {
                return localTime;
            }
        } else {
            return localTime;
        }
    } else if (month == 9){
        if (day < 30) {
            return localTime;
        } else if (day == 30){
            if (timeUTC > 1400) {
                if (localTime == 200 || localTime > 200) {
                    int a;
                    a = conversionDST2(localTime);
                    return a;
                } else {
                    return localTime;
                }
            } else {
                return localTime;
            }
        } else {
            return localTime;
        }
    } else {
        return localTime;
    }
}
int NZDST (int city, int day, int month, int localTime, int timeUTC) {
    if (month > 4 && month < 9) {
        return localTime;
    } else if (month < 4 || month > 9) {
        int a;
        a = conversionDST1(localTime);
        return a;
    } else if (month == 4) {
        if (day > 2) {
            return localTime;
        } else if (day == 1){
            if (timeUTC >= 1200) {
                if (localTime == 200 || localTime > 200) {
                    return localTime;
                } else {
                    int a;
                    a = conversionDST1(localTime);
                    return a;
                }
            } else {
                int a;
                a = conversionDST1(localTime);
                return a;
            }
        } else if (day == 2) {
            if (localTime < 200) {
                int a;
                a = conversionDST1(localTime);
                return a;
            } else if (localTime == 200 || localTime > 200) {
                return localTime;
            } else {
                return localTime;
            }
        } else {
            return localTime;
        }
    } else if (month == 9) {
        if (day < 23) {
            return localTime;
        } else if (day > 24){
            int a;
            a = conversionDST1(localTime);
            return a;
        } else if (day == 23) {
            if (timeUTC > 1300) {
                if (localTime == 200 || localTime > 200) {
                    int a;
                    a = conversionDST1(localTime);
                    return a;
                } else {
                    return localTime;
                }
            } else {
                return localTime;
            }
        } else if (day == 24) {
            int a;
            a = conversionDST1(localTime);
            return a;
        } else {
            return localTime;
        }
    } else {
        return localTime;
    }
}
