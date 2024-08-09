#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct task{
    string description;
    bool completed;
    task(string desc):description(desc),completed(false){}
};
class ToDoList{
    private:
       vector<task> tasks;
    public:
       void addtask(const string& description){
           tasks.push_back(task(description));
           cout<<"Task added: "<<description<<endl;
       }  
       void viewTasks() const{
        if(tasks.empty()){
            cout<<"No tasks available."<<endl;
            return;
        }
        cout<<"To-Do List:"<<endl;
        for(size_t i=0;i<tasks.size();i++){
            cout<<i+1<<". "<<(tasks[i].completed?"[completed] ":"[pending] ")<<tasks[i].description<<endl;
        }
       } 
       void markTaskcompleted(int taskindex){
        if(taskindex>=1 && taskindex<=tasks.size()){
            tasks[taskindex-1].completed=true;
            cout<<"Task marked as completed: "<<tasks[taskindex-1].description<<endl;
        }
        else{
            cout<<"Invalid task number."<<endl;
        }
       }
       void removeTask(int taskindex){
        if(taskindex>=1&&taskindex<=tasks.size()){
            cout<<"Task removed: "<<tasks[taskindex-1].description<<endl;
            tasks.erase(tasks.begin()+taskindex-1);
        }
        else{
            cout<<"Invalid task number."<<endl;
        }
       }
};

int main(){
    ToDoList todolist;
    int choice;
    string description;
    int taskindex;
    do{
        cout<<"\nTo-Do List Manager:"<<endl;
        cout<<"1. Add Task"<<endl;
        cout<<"2. View Tasks"<<endl;
        cout<<"3. Mark Task as completed"<<endl;
        cout<<"4. Remove Task"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        cin.ignore();

        switch(choice){
            case 1:
                cout << "Enter the task description: ";
                getline(cin, description);
                todolist.addtask(description);
                break;
            case 2:
                todolist.viewTasks();
                break;
            case 3:
                cout << "Enter the task number to mark as completed: ";
                cin >> taskindex;
                todolist.markTaskcompleted(taskindex);
                break;
            case 4:
                cout << "Enter the task number to remove: ";
                cin >> taskindex;
                todolist.removeTask(taskindex);
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
 }
    