#include "gameMap.h"
#include "player.h"

Map::Map(int height_, int width_){			//Constructor, generate a map with inputted height and width
	width = width_;
	height = height_;
	for (int i=1;i<=height/2;i++){			//The upper half is created as empty.
		std::vector<Block> temp_line;
		Block temp_block = b_0;
		for (int j=1;j<=width;j++){
			temp_line.push_back(temp_block);
		}
		mp.push_back(temp_line);
	}
	for (int i=height/2;i<=height;i++){ 		//The lower half is created with solid blocks.
		std::vector<Block> temp_line;
		Block temp_block = b_0;
		for (int j=1;j<=width;j++){
			temp_line.push_back(temp_block);
		}
		mp.push_back(temp_line);
	}
}

Map::Map(){						//Default Constructor
	width = 20;
	height = 12;
	for (int i=0;i<=height/2;i++){
		std::vector<Block> temp_line;
		Block temp_block = b_00;
		for (int j=1;j<=width;j++){
			temp_line.push_back(temp_block);
		}
		mp.push_back(temp_line);
	}
	for (int i=height/2+1;i<height;i++){
		std::vector<Block> temp_line;
		Block temp_block = b_0;
		for (int j=1;j<=width;j++){
			temp_line.push_back(temp_block);
		}
		mp.push_back(temp_line);
	}
}

void Map::show_map(const Player& p){//The function of printing the map
	std::cout<<"\n\n\n\n\n"<<std::endl;
	int i=0; int j=0; //iterators cannot be read directly, use i,j to count
	for(auto & it : mp){
		for(auto & jt : it){
			if (i==p.getY() && j==p.getX()){		//(*jt) represents the current block
				std::cout<<p.getAppearance();
				j++;
				continue;
			}
			
			if (jt.get_id()=="white")
				std::cout<<"\033[0m";			//Set the block color according to the block id
			if (jt.get_id()=="green")
				std::cout<<"\033[32m";
			else if (jt.get_id()=="blue")
				std::cout<<"\033[34m";
			else if (jt.get_id()=="yellow")
				std::cout<<"\033[33m";
			else if (jt.get_id()=="pink")
				std::cout<<"\033[35m";
			else if (jt.get_id()=="red")
				std::cout<<"\033[31m";
			else if (jt.get_id()=="cyan")
				std::cout<<"\033[37m";
			else if(jt.get_id()=="black")
				std::cout<<"\033[90m";
			if(jt.get_status() == 1)
				std::cout<<jt.get_appearance()<<"  ";
			else if(jt.get_status() == 2)
				std::cout<<jt.get_breaking_app();
			else if(jt.get_status() == 0)
				std::cout<<' ';
			std::cout <<"\033[0m"; 				// Reset color to default
			j++;
		}
		j=0;				// End of printing a line of the map
		if(i==3) std::cout<<"\t current depth:"<<p.getDepth();
		else if(i==4) std::cout<<"\t wealth:"<<p.getWealth()<<"  level:"<<p.getLevel();
		else if(i==5) std::cout<<"\t Bombs:"<<p.getBombNum()<<"  Oxygen pack:"<<p.getTime()<<"\\"<<p.getOxygen();
		else if(i==6) std::cout<<"\t Use a,s,d to move";
		else if(i==7) std::cout<<"\t Press 'r' to go back to the base";

		i++;
		std::cout<<std::endl;
	}
}

void Map::generateLine(const Player& p){ 	//Generate a new line according to player's depth
	std::vector<Block> temp_line;
	Block normal;
	Block special;
	normal.copy(b_0);
	special.copy(b_0);
	
	if(p.getDepth()>10&&p.getDepth()<=20)		//Check depth range
	{
		normal.copy(b_1);
		special.copy(s_1);
	}
	else if(p.getDepth()>20&&p.getDepth()<=40){
		normal.copy(b_2); 
		special.copy(s_2);
	}
	else if(p.getDepth()>40&&p.getDepth()<=60){
		normal.copy(b_3); 
		special.copy(s_3);
	}
	else if(p.getDepth()>60&&p.getDepth()<=80){
		normal.copy(b_4); 
		special.copy(s_4);
	}
	else if(p.getDepth()>80&&p.getDepth()<=100){
		normal.copy(b_5); 
		special.copy(s_5);
	}
	else if(p.getDepth()>100){
		normal.copy(b_6); 
		special.copy(s_6);
	}
	for (int j=1;j<=width;j++){				//Randomly generate normal and special blocks into the new line
		int num = rand()%10+1;
		if (num%5 == 0) 
			temp_line.push_back(special);
		else if(num%9 == 0){
			temp_line.push_back(ob_0);
		}
		else 
			temp_line.push_back(normal);
	}
	
	mp.push_back(temp_line);
	mp.pop_front();
	
}


