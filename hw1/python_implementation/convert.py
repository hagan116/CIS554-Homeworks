#!usr/bin/python
import math

class Convert:

    @staticmethod
    def convert(number,base):
        count = 0
        result = 0
        lsDigit = None
        
        while (number > 0):
            lsDigit = number % 10
            if (lsDigit >= base):
                print "Invalid input."
                return 0
            number = number / 10
            result = result + (lsDigit * math.pow(base,count))
            count += 1

        return result;
