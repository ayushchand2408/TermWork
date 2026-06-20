#include <iostream>
#include <string>
using namespace std;

class Member{
    private:
        int MemberID;
        string MemberName;
        string MemberType;
    public:
        static int memberCount;
        Member(int MemberID, string MemberName, string MemberType):
        MemberID(MemberID), MemberName(MemberName), MemberType(MemberType){
            memberCount++;
        }

        int getMemberID(){
            return MemberID;
        }

        string getMemberName(){
            return MemberName;
        }

        string getMemberType(){
            return MemberType;
        }
};
int Member::memberCount=0;

class Book{
    private:
        int BookID;
        string Title;
        string Publisher;
        string Author;
        int Edition;
    public:
        static int bookCount;
        Book(int BookID,string Title,string Publisher,string Author,int Edition):
        BookID(BookID),Title(Title),Publisher(Publisher),Author(Author),Edition(Edition){
            bookCount++;
        }

        int getBookId(){
            return BookID;
        }

        string getTitle(){
            return Title;
        }

        string getPublisher(){
            return Publisher;
        }
};
int Book::bookCount=0;

class Journal : public Book{
    private:
        string Editor;
        int Volume;
    public:
        Journal(int BookID, string Title, string Publisher, string Author, int Edition, string Editor, int Volume) : 
        Book(BookID, Title, Publisher, Author, Edition), Editor(Editor), Volume(Volume){}  
};

class LibraryDB{
    public:
        Member *members[50]; 
        Book *books[50];         
        int BooksTaken[50];
        int BookStatus[50];
    public:
        LibraryDB(){
            for(int i=0;i<50;i++){
                BooksTaken[i]=0;
                BookStatus[i]=1;
            }
        }
        bool ValidateMemberEligibility(int MemberID){
            for(int i=0;i<Member::memberCount;i++){
                if(MemberID==members[i]->getMemberID()){
                    return true;
                }
            }
            return false;
        }

        bool ValidateBookAvailability( int BookID ){
            for(int i=0;i<Book::bookCount;i++){
                if(BookID==books[i]->getBookId()){
                    if(BookStatus[i]==1)  return true;
                    else return false;
                }
            }
            return false;
        }

        void IssueBook(int MemberID, int BookId){
            for(int i=0;i<Member::memberCount;i++){
                if(MemberID==members[i]->getMemberID()){
                    BooksTaken[i]++;
                }
            }
            for(int i=0;i<Book::bookCount;i++){
                if(BookId==books[i]->getBookId()){
                    BookStatus[i]=0;
                }
            }
            cout<<"Book has been succesfully issued."<<endl;
        } 

        int getMember(int memberID){
            for(int i=0;i<Member::memberCount;i++){
                if(memberID==members[i]->getMemberID()) return i;
            }
            return -1;
        } 

        int getBook(int bookid){
            for(int i=0;i<Book::bookCount;i++){
                if(bookid==books[i]->getBookId()) return i;
            }
            return -1;
        }
};

class Transaction{
    private:
        Member *memberObj;
        Book *bookObj;
        LibraryDB *library;
        int transactionId;
    public:
        Transaction(Member *memberObj, Book *bookObj,LibraryDB *library,int transactionId):
        memberObj(memberObj), bookObj(bookObj), library(library),transactionId(transactionId){}
        
        bool BorrowBook(){
            if(!library->ValidateMemberEligibility(memberObj->getMemberID())){
                cout<<"Member doesn't exist"<<endl;
                return false;
            }
            if(!library->ValidateBookAvailability(bookObj->getBookId())){
                cout<<"Sorry! Book is not avaialable"<<endl;
                return false;
            }
            library->IssueBook(memberObj->getMemberID(),bookObj->getBookId());
            cout<<"Book has been ready for borrowing"<<endl;
            return true;
        }

        void display(int day, int month, int year){
            int rday = (day + 14)%30;
            int rmonth = (month + (day + 14)/30)%12;
            int ryear= year + (month + (day + 14)/30)/12;
            cout<<"Borrowed Date:"<<day<<"/"<<month<<"/"<<year<<endl;
            cout<<"Return Date:"<<rday<<"/"<<rmonth<<"/"<<ryear<<endl;          
        }
};

void menuDisplay(){
    cout<<"Press 1 to enter New Member"<<endl;
    cout<<"Press 2 to enter New Book"<<endl;
    cout<<"Press 3 to issue book"<<endl;
    cout<<"Press 4 to borrow book"<<endl;
    cout<<"Press 0 to exit"<<endl;
}

int main(){
    LibraryDB *mainLib= new LibraryDB();
    int choice;
    menuDisplay();
    do{
        cout<<"\nEnter your choice:";
        cin>>choice;
        switch(choice){
            case 1:{
                string name,type;
                int id;
                cout<<"\tEnter the Name:";
                cin>>name;
                cout<<"\tEnter the member type:";
                cin>>type;
                cin.ignore();
                cout<<"\tEnter the id:";
                cin>>id;
                int indx=Member::memberCount;
                mainLib->members[indx] = new Member(id,name,type);
                cout<<"Member has been added to the DataBase"<<endl;
                break;
            }
            case 2:{
                int bookID, edition,volume,issue,type;
                string  title, publisher, author,editor;
                cout<<"\t    Press 1 for Normal books"<<endl;
                cout<<"\t    Press 2 for Journal"<<endl;
                cout<<"\t    Enter the book type:";
                cin>>type;
                cout<<"\tEnter the Title:";
                getline(cin,title);
                cout<<"\tEnter the publisher:";
                cin>>publisher;
                cout<<"\tEnter the author:";
                cin>>author;
                cin.ignore();
                cout<<"\tEnter the bookId:";
                cin>>bookID;
                cout<<"\tEnter the edition:";
                cin>>edition;
                int indx=Book::bookCount;
                if(type==2){
                    cout<<"\tEnter the volume:";
                    cin>>volume;
                    mainLib->books[indx] = new Journal(bookID,title,publisher,author,edition,editor,volume);
                }else{
                    mainLib->books[indx] = new Book(bookID,title,publisher,author,edition);
                }
                cout<<"Book has been added to the DataBase"<<endl;
                break;
            }
            case 3:{
                int memid,bookid;
                cout<<"\tEnter the MemberID:";
                cin>>memid;
                if(!mainLib->ValidateMemberEligibility(memid)){
                    cout<<"No such user exist"<<endl;
                    break;
                }
                cout<<"\tEnter the BookID:";
                cin>>bookid;
                if(!mainLib->ValidateBookAvailability(bookid)){
                    cout<<"Sorry! book is not available"<<endl;
                    break;
                }
                mainLib->IssueBook(memid,bookid);
                break;
            }
            case 4:{
                int day,month,year,memid,bookid,transid;
                cout<<"\tEnter the MemberID:";
                cin>>memid;
                cout<<"\tEnter the BookID:";
                cin>>bookid;
                cout<<"\tEnter date month year:";
                cin>>day>>month>>year;
                cout<<"\tEnter Transaction no:";
                cin>>transid;
                Transaction obj(mainLib->members[mainLib->getMember(memid)],mainLib->books[mainLib->getBook(bookid)],mainLib,transid);
                if(obj.BorrowBook()){
                    obj.display(day,month,year);
                }
                break;
            }
            case 0:{
                cout<<"Thankyou! Exiting the program"<<endl;
            }
        }
    }while(choice!=0);
return 0;
}