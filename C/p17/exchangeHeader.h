#ifndef EXCHANGEHEADER_H
#define EXCHANGEHEADER_H

int hundredsOrOnesExchange(int digit)
{
    switch(digit)
    {
        case 1:
            return ONE;
        case 2:
            return TWO;
        case 3:
            return THREE;
        case 4:
            return FOUR;
        case 5:
            return FIVE;
        case 6:
            return SIX;
        case 7:
            return SEVEN;
        case 8:
            return EIGHT;
        case 9:
            return NINE;
        default: //zero hundred or zero ones
            return 0;
    }
}

int tenToNineteenExchange(int number)
{
    switch(number)
    {
        case 10:
            return TEN;
        case 11:
            return ELEVEN;
        case 12:
            return TWELVE;
        case 13:
            return THIRTEEN;
        case 14:
            return FOURTEEN;
        case 15:
            return FIFTEEN;
        case 16:
            return SIXTEEN;
        case 17:
            return SEVENTEEN;
        case 18:
            return EIGHTEEN;
        case 19:
            return NINETEEN;
        default:
            return 0;
    }
}

int tensExchange(int number)
{
    switch(number)
    {
        case 2:
            return TWENTY;
        case 3:
            return THIRTY;
        case 4:
            return FORTY;
        case 5:
            return FIFTY;
        case 6:
            return SIXTY;
        case 7:
            return SEVENTY;
        case 8:
            return EIGHTY;
        case 9:
            return NINETY;
        default:
            return 0;
    }
}

#endif
