#include<iostream>

using namespace std;
class fruit{
	private:
		string fruit_name;
	public:
		fruit(){
			
		}
		fruit(string fruit_name){
			this->fruit_name = fruit_name;
		}
};
class fruit_grams: public fruit{
	private :
		double available_kgs;	
		double price_per_kg;
	public:
		fruit_grams(string fruit_name,double available_kgs,double price_per_kg):fruit(fruit_name){
			this->available_kgs = available_kgs;
			this->price_per_kg = price_per_kg;		
		}
		
		bool checkAvailability(double need){
			if(available_kgs > need) {
				return true;
			}
			else{
				return false;
			}
		}
		
		void updateAvailability(double need) {
			available_kgs = available_kgs - need;
		}
		
		double getAvailableKgs(){
			//cout<<"available kgs : "<<available_kgs<<endl;
			return available_kgs;
		}
		
		double getPricePerKg(){
			//cout<<"price : "<<price_per_kg<<endl;
			return price_per_kg;
		}
};


class fruit_in_pcs:public fruit{
	private :
		int available_pcs;	
		double price_per_piece;
	public:
		fruit_in_pcs(string fruit_name,int available_pcs,double price_per_piece):fruit(fruit_name){
			this->available_pcs = available_pcs;
			this->price_per_piece = price_per_piece;		
		}
		
		bool checkAvailability(int pcs){
			if(available_pcs > pcs) {
				return true;
			}
			else{
				return false;
			}
		}
		
		void updateAvailability(double pcs) {
			available_pcs = available_pcs - pcs;
		}
		
		double getAvailablePcs(){
			//cout<<"available piece : "<<available_pcs<<endl;
			return available_pcs;
		}
		
		double getPricePerPiece(){
			//cout<<"price : "<<price_per_piece<<endl;
			return price_per_piece;
		}
};

class sale{
	private:
		fruit_grams *fgms=NULL;
		fruit_in_pcs *fpcs=NULL;
		double unit;
		double amount;
		
	public:
		sale(fruit_grams *fgms,double unit) {
			this->fgms = fgms;
			this->unit = unit;
		}
		sale(fruit_in_pcs *fpcs,double unit){
			this->fpcs = fpcs;
			this->unit = unit;
		}
		double bill(){
			if(fgms!=NULL){
				amount = unit * fgms->getPricePerKg();
			}
			if(fpcs!=NULL){
				amount = unit * fpcs->getPricePerPiece();
			}
			if(amount >= 500){
				amount = discount();
			}
			return amount;
		}
		
		double discount(){
			amount = amount - (0.05 * amount);
			return amount;
		}

};
int main()
{
	fruit_grams fgms("mango",100.00,50.00);
	double ammount,no_of_pieces;
	cout<<"enter the ammount of fruit you wanted in kg : ";
	cin>>ammount;
	if(fgms.checkAvailability(ammount) == 1)
	{
		sale s1(&fgms,ammount);
		cout <<s1.bill()<<endl;
	}else{
		cout<<"not sufficient stock";
	}
	fruit_in_pcs fpcs("banana",100,50.0);
	cout<<"enter the ammount of fruit you wanted in pcs : ";
	cin>>no_of_pieces;
	if(fpcs.checkAvailability(no_of_pieces) == 1)
	{
		sale s2(&fpcs,no_of_pieces);
		cout <<s2.bill()<<endl;
	}else{
		cout<<"not sufficient stock";
	}
}