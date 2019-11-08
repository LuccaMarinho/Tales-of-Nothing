#include "dice.hpp"

short Dice::roll_dice(short num){
	switch(num){
		case 4:
			return (rand() % 4) + 1;
	        break;

	    case 6:
	        return (rand() % 6) + 1;
	        break;

	    case 8:
	    	return (rand() % 8) + 1;
	      	break;

	    case 10:
	        return (rand() % 10) + 1;
	        break;

	  	case 12:
	    	 return (rand() % 12) + 1;
	         break;

	    case 16:
	         return (rand() % 16) + 1;
	         break;

	    case 20:
	         return (rand() % 20) + 1;
	         break;

	    default:
	         return 0;
	         break;
	}   
}
