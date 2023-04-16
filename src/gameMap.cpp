#include "gameMap.h"
#include <iostream>

Map::Map(int height_, int width_){
	width = width_;
	height = height_;
	for (int i=1;i<=height/2;i++){
		std::vector<Block> temp_line;
		Block temp_block = b_0;
		for (int j=1;j<=width;j++){
			temp_line.push_back(temp_block);
		}
		mp.push_back(temp_line);
	}
	for (int i=height/2;i<=height;i++){ 
		std::vector<Block> temp_line;
		Block temp_block = b_0;
		for (int j=1;j<=width;j++){
			temp_line.push_back(temp_block);
		}
		mp.push_back(temp_line);
	}
}

Map::Map(){
	width = 20;
	height = 12;
	for (int i=1;i<=height/2;i++){
		std::vector<Block> temp_line;
		Block temp_block = b_00;
		for (int j=1;j<=width;j++){
			temp_line.push_back(temp_block);
		}
		mp.push_back(temp_line);
	}
	for (int i=height/2;i<=height;i++){ 
		std::vector<Block> temp_line;
		Block temp_block = b_0;
		for (int j=1;j<=width;j++){
			temp_line.push_back(temp_block);
		}
		mp.push_back(temp_line);
	}
}

void Map::show_map(const Player& p){ 				// Print the map
	cout<<"\n\n\n\n\n"<<endl;
	int i=0; int j=0; //iterators cannot be read directly, use i,j to count
	for(deque<vector<Block> >::iterator it = mp.begin();it!=mp.end();it++){  
		for(vector<Block>::iterator jt = (*it).begin(); jt!= (*it).end();jt++){
			if (i==p.getY() && j==p.getX()){		//(*jt) is the current block
				cout<<p.getAppearance();
				j++;
				continue;
			}
			
			if ((*jt).get_id()=="white")
				cout<<"\033[0m";								//set the color according to the block name
			if ((*jt).get_id()=="green")
				cout<<"\033[32m";
			else if ((*jt).get_id()=="blue")
				cout<<"\033[34m";
			else if ((*jt).get_id()=="yellow")
				cout<<"\033[33m";
			else if ((*jt).get_id()=="pink")
				cout<<"\033[35m";
			else if ((*jt).get_id()=="red")
				cout<<"\033[31m";
			else if ((*jt).get_id()=="cyan")
				cout<<"\033[37m";
			else if((*jt).get_id()=="black")
				cout<<"\033[90m";
			if((*jt).get_status() == 1)
				cout<<(*jt).get_appearance()<"  "; 	
			else if((*jt).get_status() == 2)
				cout<<(*jt).get_breaking_app();
			else if((*jt).get_status() == 0)			
				cout<<' ';
			cout <<"\033[0m"; 								// reset color to default
			j++;
		}
		j=0;	// End of each line
		if(i==4) cout<<"\t current depth:"<<p.getDepth();
		else if(i==5) cout<<"\t wealth:"<<p.getWealth()<<" level:"<<p.getLevel();
		else if(i==6) cout<<"\t Use a,s,d to move";
		else if(i==7) cout<<"\t Press 'r' to go back to the base";

		i++;
		cout<<endl;
	}
}

void Map::generateLine(const Player& p){ //according to player's depth
		srand(time(NULL));
	vector<Block> temp_line;
	Block normal;
	Block special;
	normal.copy(b_0);
	special.copy(b_0);
	
	if(p.getDepth()>10&&p.getDepth()<=20)					//check depth
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
	for (int j=1;j<=width;j++){				//randomly generate normal and special blocks
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

//int Map::getWidth() const{
//    return Map::WIDTH;
//}
//
//
//int Map::getHeight() const{
//    return Map::HEIGHT;
//}
