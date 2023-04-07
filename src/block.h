#include <string>
#ifndef BLOCK
#define BLOCK
#endif

class Block{
private:
	string id;
    char appearance;
    char breaking_app;
    int health;
    int value;
    int status;
public:   
    string get_id(){
		return id;
	}
	char get_appearance(){
		return appearance;
	}
    char get_breaking_app(){
    	return breaking_app;
	}
    int get_health(){
    	return health;
	}
    int get_value(){
    	return value;
	}
    int get_status(){
    	return status;
	}
	// Default constructor
    Block() {
        id = "white";
        appearance = '#';
        char breaking_app='*';
        health = 2;
        value = 1;
        status = 1;
    }
    
    // Constructor with parameters
    Block(string id_, char appearance_,char breaking_app_, int health_, int value_, int status_) {
        id = id_;
        appearance = appearance_;
        breaking_app = breaking_app_;
        health = health_;
        value = value_;
        status = status_;
    }
	
	copy(Block target){ //快速给新方块赋值用的
		id = target.id;
        appearance = target.appearance;
        char breaking_app=target.breaking_app;
        health = target.health;
        value = target.value;
        status = target.status;
	}
	
	int attack(int damage){ //如果方块已经是空的返回1, 攻击破坏成功返回2,未破坏返回0 
		if (health>0){
			health=health-damage;
			if(health<=0){
				status=0;
				health=0;
				return 2;
			}
			else return 0;
		}
		else{
			return 1;
		}
	}
};
//health:线性增长
//value:指数增长 
Block b_0("white",'#','*',2,1,1)
Block b_1("green",'#','*',3,2,1)
Block b_2("blue",'#','*',4,4,1)
Block b_3("yellow",'#','*',5,8,1)
Block b_4("red",'#','*',6,16,1)
Block b_5("pink",'#','*',7,32,1)
Block b_6("cyan",'#','*',8,64,1)
//special blocks with higher values:
Block s_0("white",'$','$',1,10,1)
Block s_1("green",'$','$',1,20,1)
Block s_2("blue",'$','$',1,40,1)
Block s_3("yellow",'$','$',1,80,1)
Block s_4("red",'$','$',1,160,1)
Block s_5("pink",'$','$',1,320,1)
Block s_6("cyan",'$','$',1,640,1)

//30: black
//31: red
//32: green
//33: yellow
//34: blue
//35: magenta
//36: cyan
//37: white
