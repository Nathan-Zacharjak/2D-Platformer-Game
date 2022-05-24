//#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

int main(){

float rand_y = rand(); 
float rand1 = rand(); 
float rand2 = (float)rand()/RAND_MAX ; 
std::cout<<rand_y<<std::endl;
std::cout<<rand1<<std::endl;
std::cout<<rand2<<std::endl;
}