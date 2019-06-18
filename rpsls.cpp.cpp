//Scissors cuts Paper.
//Paper covers Rock.
//Rock crushes Lizard.
//Lizard poisons Spock.
//Spock smashes Scissors.
//Scissors decapitate Lizard.
//Lizard eats Paper.
//Paper disproves Spock.
//Spock vaporizes Rock.
//(and as it always has) Rock crushes Scissors.
#include <iostream>
#include <stdlib.h>
int main() {
 	// Live long and prosper
	int user;
 	srand(time(NULL));
 	int computer=rand()%5+1;
  	std::cout << "====================\n";
	std::cout << "rock paper scissors!\n";
	std::cout << "====================\n";
	std::cout << "1) rock\n";
	std::cout << "2) paper\n";
	std::cout << "3) scissors\n";
	std::cout << "4) Lizard \n";
	std::cout << "5) spock\n";
	std::cout << "shoot! \n";
	std::cin >> user;
 	if(user==1){
    	if(computer==1){
      		std::cout<<"Tie!\n";
    	}else if(computer==2){
      		std::cout<<"Paper covers rock.  Computer wins.\n";
    	}else if(computer==3){
      		std::cout<<"Rock crushes scissors.  You win!\n";
    	}else if(computer==4){
      		std::cout<<"Rock crushes scissors.  You win!\n";
    	}else if(computer==5){
      		std::cout<<"Spock vaporizes rock!  You got destroyed!\n";
    	}
  	}else if(user==2){
     	if(computer==1){
      		std::cout<<"Paper covers rock.  You win!.\n";
    	}else if(computer==2){
        	std::cout<<"Tie!\n";
    	}else if(computer==3){
      		std::cout<<"Scissors cut paper.  Computer wins.\n";
    	}else if(computer==4){
    		std::cout<<"Lizard eats paper.  Computer wins.\n";
    	}else if(computer==5){
      		std::cout<<"Paper disproves spock!  You win!.\n";
    	}
 	}else if(user==3){
    	if(computer==1){
    		std::cout<<"Rock smashes scissors.  Computer wins.\n";
    	}else if(computer==2){
      		std::cout<<"Scissors cuts paper.  You win!.\n";
    	}else if(computer==3){
    		std::cout<<"Tie!\n";
    	}else if(computer==4){
    		std::cout<<"Scissors decapitate lizard.  You win!\n";
    	}else if(computer==5){
    		std::cout<<"Spock smashes scissors.  Computer wins.\n";
    	}
  	}else if(user==4){
    	if(computer==1){
      		std::cout<<"Rock smashes scissors.  Computer wins.\n";
    	}else if(computer==2){
    		std::cout<<"Lizard eats paper.  You win!.\n";
    	}else if(computer==3){
      		std::cout<<"Scissors decapitates lizard.  Computer wins.\n";
    	}else if(computer==4){
        	std::cout<<"Tie!\n";
    	}else if(computer==5){
			std::cout<<"Lizard poisons Spock.  You win!\n";
    }
  	}else if(user==5){
     	if(computer==1){
      		std::cout<<"Spock vaporizes rock.  You utterly and ruthlessly destroyed your opponent.\n";
    	}else if(computer==2){
      		std::cout<<"Paper disproves spock even though he can not be disproved.  Physics has been violated and a wormhole opens up killing you both.  You all lose.\n";
    	}else if(computer==3){
      		std::cout<<"Spock smashes scissors with his Vulcan strength.  The Vulcan (you) wins.\n";
    	}else if(computer==4){
      		std::cout<<"Lizard poisons spock!  Computer wins.\n";
    	}else if(computer==5){
         	std::cout<<"Tie!\n";
    	}
  	}
}
