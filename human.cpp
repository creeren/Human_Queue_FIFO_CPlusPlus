#include <iostream>

using namespace std;


class Human{
	friend ostream &operator<<(ostream&, const Human&);

	
public:
   Human(string, int, float);
   Human();
   ~Human();
   void setHuman(string, int, float);
   string getfirstName();
   int getAge();
   float getHeight();  
 
 
private:
   string firstName;
   int age;
   float height;
};


void Human::setHuman(string n, int a, float h) {
	
   firstName = n; 
   age = a;
   height = h; 
}

Human::Human(string n, int a, float h) {
	
   setHuman(n, a, h);
}

Human::Human() { 
	
age=height=0.0;
firstName="";

}

Human::~Human() {}


string Human::getfirstName() { 

   return firstName;  
}

int Human::getAge(){ 

   return age;  
}

float Human::getHeight() { 

   return height;  
}

ostream &operator<<(ostream &izvade, Human &obj) {
	
    izvade << " Name: " << obj.getfirstName() << " | Age: " << obj.getAge() << " | Height: " << obj.getHeight() ;
    return izvade;
}

template<class T> 
class Queue{ 

public: 
   Queue(int size); 
   ~Queue(); 
   void PrintQueue(); 
   int enqueue(T);
   void dequeue();

private: 
   T *data; 
   int size; 
   int index; 
}; 

template<class T> 
Queue<T>::Queue(int s) { 

   data = new T[s];
    
   if (data == NULL) { 
      cout << "Program ended running out of memory!" << endl; 
      exit(1); 
   } 
   size = s; 
   index = 0; 
} 

template<class T>
Queue<T>::~Queue() {
	
   delete [] data;       
}

template<class T> 
void Queue<T>::PrintQueue() { 

   int counter=0;
   cout << endl;
   for (int i=index-1; i>=0; i--) {
   		
   		counter++;
   		cout << "Number in queue: " << counter << "." <<  data[i] << endl; 
    }
    cout << endl;
} 


template<class T> 
int Queue<T>::enqueue(T value) {
	
	int counter=index+1;
	
	cout << "Enqueued NR: " << counter << "." << value << endl;
	
    if (index == size) return(1); // full arrry
  
    else{
         for(int i=index; i>0; i--) {
         	
             data[i]=data[i-1]; //all elements moves for one place forward  
         }
         data[0] = value; //insert element in index 0
         
         index++; //increase array for one element
         return 0;
    }
}

template<class T> 
void Queue<T>::dequeue() {

		if(index>0) {	
				cout << "-----Dequeue from queue----" << data[index-1] << endl; //removes first element
			
			index--;	
		}
}

int main() { 
   Queue<Human> HumanQueue(200); 
   
    Human h("Elis", 30, 1.71);
    HumanQueue.enqueue(h);  	 
    
   	Human h1("Isabella",29, 1.69); 
	HumanQueue.enqueue(h1);

    Human h2("Kriss",25, 1.65); 
	HumanQueue.enqueue(h2);
	
	Human h3("Sofia",23, 1.74); 
	HumanQueue.enqueue(h3);
	
	Human h4("Victoria",23, 1.75); 
	HumanQueue.enqueue(h4);
	
    HumanQueue.PrintQueue(); 
    HumanQueue.dequeue();
    HumanQueue.PrintQueue();
	 
    Human h5("Chloe", 31, 1.72); 
	HumanQueue.enqueue(h5);
	
	Human h6("Evelyn", 28, 1.73); 
	HumanQueue.enqueue(h6);
	
	HumanQueue.PrintQueue();
	HumanQueue.dequeue();
	HumanQueue.PrintQueue();
	
   system("PAUSE");	
   return 0;
}


