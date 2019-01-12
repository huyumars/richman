#include<iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <algorithm>

class People {
  public:
    People(int w):wealth(w){};
    void giveMoney(People & other, int amount){
      wealth -= amount;
      other.wealth += amount;
    }
    int getwealth() const {return wealth;}
  private:
    int wealth;
};

class World {
  public:
    World( int  nums = 100, int initWealth = 50)
      :_nums(nums),pls(nums)
    {
      for(auto & p :pls){
        p = std::make_unique<People>(initWealth);
      }
    }
    typedef std::unique_ptr<People> PeoplePtr;
    typedef std::vector<PeoplePtr>  PeopleList;
    void run(int times = 1000){
      while(times--){
        oneLoop();
        sort();
        print();
      }
    }
  private:
    void sort(){
      std::sort(pls.begin(), pls.end(), [](PeoplePtr &p1, PeoplePtr &p2){
          return p1->getwealth() < p2->getwealth();
          });
    }
    void oneLoop(){
      for(int i=0;i<_nums; ++i){
        int to = randNum();
        pls[i]->giveMoney(*pls[to], 1);
      }
    }
    void print(int divide=20){
      for(auto & p : pls){
        std::cout<<p->getwealth()<<"   ";
      }
      std::cout<<std::endl;
    }
    int randNum() const{
      return std::rand()%_nums;
    }
    int _nums;
    PeopleList    pls;
};


int main(){
  World w(10,50);
  w.run();
}
