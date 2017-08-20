
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
