#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 

using namespace std;

/*You need to change the file locations for the text files based on your computer.*/

class addRecord{
		
	public:
		fstream fs;
		int choice;
		int walk, calorie;
		double water;
			
		void f_AddRecord(){
			
			system("cls"); // I know it's a bad practice to use this command but for the simplicity of code it's better I guess :).
			
			cout<<"Please make a choice"<<endl;
			cout<<"1. Add Exercise"<<endl;
			cout<<"2. Add Calorie"<<endl;
			cout<<"3. Add Water"<<endl;
			
			cin>>choice;
			
			/* ------------------Store Exercise----------------------*/
			if(choice == 1){
				
				fs.open("C:\\Pedometer\\exercise.txt", ios::out | ios::app);
				
				system("cls");
				cout<<"Please enter the time that you exercised in minute: "<<endl;
				cin>>walk;
				
				fs << walk << endl;
				
				fs.close(); 		
			}
			/* ------------------Store Calorie----------------------*/
			if(choice == 2){
				
				fs.open("C:\\Pedometer\\calorie.txt", ios::out | ios::app);
				
				system("cls");				
				cout<<"Please enter the amount of calorie that you have: "<<endl;
				cin>>calorie;
				
				fs << calorie << endl;
				
				fs.close(); 		
			} 
			
			/* ------------------Store Water----------------------*/
			if(choice == 3){
				
				fs.open("C:\\Pedometer\\water.txt", ios::out | ios::app);
				
				system("cls");
				cout<<"Please enter the amount of water that you drink in litre: "<<endl;
				cin>>water;
				
				fs << water << endl;
				
				fs.close(); 		
			}
			
			 
		}	
}; // end of class


class showRecord{

	private:
		int Exercise, Calorie;
		double Water;
		
   	public:		      
	    fstream fs;
	   	string line;
	   	int intLine; /* For string conversions */
	   	double doubleLine;
		int choice; 
	     	 	 	
   	void f_ShowRecord(){
		
		Exercise = 0;
		Calorie = 0;
		Water = 0.0;

	/*------------Exercise calculation-----------*/
   	fs.open("C:\\Pedometer\\exercise.txt", ios::in);
   	
   	if (fs.is_open())
	{
	    while (getline(fs, line)) 
	    {
	    	stringstream convert(line); // defining a object from stringstream class and store the string value
	        convert >> intLine; // store it in integer
			Exercise = Exercise + intLine; 
	    }
	    fs.close();
	}
	
	/*----------Calorie calculation------------*/
	fs.open("C:\\Pedometer\\calorie.txt", ios::in);
   	
   	if (fs.is_open())
	{
	    while (getline(fs, line)) 
	    {
	    	stringstream convert(line); // defining a object from stringstream class and store the string value
	        convert >> intLine; // store it in integer
			Calorie = Calorie + intLine; 
	    }
	    fs.close();
	}
	
	/*-----------Water calculation-----------*/
	fs.open("C:\\Pedometer\\water.txt", ios::in);
   	
   	if (fs.is_open())
	{
	    while (getline(fs, line)) 
	    {
	    	stringstream convert(line); // defining a object from stringstream class and store the string value
	        convert >> doubleLine; // store it in double
			Water = Water + doubleLine; 
	    }
	    fs.close();
	} 
	
	system("cls");   
   
   	cout << "The amount of time you exercised today is: " << Exercise << " minute" << endl;
   	cout << "The amount of calorie you had today is: " << Calorie << " calorie" <<endl;
   	cout << "The amount of water you drank today is: " << Water << " litre" <<"\n\n" << endl;
   	
   	/*!!!!!!!!!!!!!!! Feedback Part !!!!!!!!!!!!!!!!!!*/
   	
   	cout << "--------Daily Feedbacks----------" << "\n"<< endl;
   	
   	cout << "Exercise: ";
		if(Exercise < 50){
			
			cout << "Keep it up! You have "<< 50 - Exercise << " minute to finish your daily routine" << endl;
		}		
		else{ 
			cout << "You are doing great! You completed your daily exercise."<< endl;
		}
		
	cout << "Calorie: ";	
		if(Calorie < 2400){
			
			cout << "Keep it up! You have " << 2400 - Calorie << " calorie to complete your daily meals" << endl;
		}		
		else{
			
			cout << "You need to slow down! You had " << Calorie - 2400 << "more calorie" << endl;
		}
		
	cout << "Water: ";	
	 	if(Water < 2.0  ){
			
			cout << "Keep it up! You have "<< 2.0 - Water << " litre to get your daily water" << endl;
		}		
		else{ 
			cout << "You're great today! If you can, drink " << 3.0 - Water << " more litre \n\n" << endl;
		}
		
	/*!!!!!!!!!!!!!!!!!!! Feedback Part !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */ 
	
		
   } // end of function	
   
}; // end of class


int main(int argc, char** argv) {
	
	int choice;
	addRecord addObj;
	showRecord showObj;
	
	MainPage: //mainpage label
	system("cls"); //to clean the console
	
	cout <<	"-------------------------------------------------------------------------------" << endl;
	cout << "\t\tWELCOME TO YOUR DAILY HEALTH COACH" << endl;
	cout <<	"------------------------------------------------------------------------------- \n" << endl;
	
	cout << "Please make a choice 1.Add Record 2.Show Record: " << endl;
	cin>>choice;
	
	if(choice == 1){
		addObj.f_AddRecord();
		
		cout << "Please make a choice: 1. Go back to main menu 2.Quit " << endl;
		cin >> choice;
		if( choice == 1 ){
			goto MainPage;
		}
		else{
			return 0;
		}
	}
	else if(choice == 2){
		showObj.f_ShowRecord();
		
		cout << "Please make a choice: 1. Go back to main menu 2.Quit " << endl;
		cin >> choice;
		if( choice == 1 ){
			goto MainPage;
		}
		else{
			return 0;
		}						
	}	
			
	return 0;
}

/*
	Berkay Narin
	1804010008
	Computer Engineering
*/


