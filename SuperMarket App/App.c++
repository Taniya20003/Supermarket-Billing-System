#include <fstream>
#include <iostream>

using namespace std;

class Shopping {
private:
  int pid;
  string name;
  float dis;
  float price;

public:
  void login();
  void administrator();
  void buyer();
  void add();
  void edit();
  void rem();
  void list();
  void receipt();
};

void Shopping::login() {
start:
  int choice;
  string email;
  string password;

  cout << "\t\t\t\t_____________________________________________" << endl;
  cout << "\t\t\t\t                                             " << endl;
  cout << "\t\t\t\t           SuperMarket Login Page            " << endl;
  cout << "\t\t\t\t                                             " << endl;
  cout << "\t\t\t\t_____________________________________________" << endl;
  cout << "\t\t\t\t                                             " << endl;
  cout << "\t\t\t\t              1) Administrator               " << endl;
  cout << "\t\t\t\t                                             " << endl;
  cout << "\t\t\t\t              2) Buyer                       " << endl;
  cout << "\t\t\t\t                                             " << endl;
  cout << "\t\t\t\t              3) Exit                        " << endl;
  cout << "\t\t\t\t                                             " << endl;
  cout << "\t\t\t\t           Please select the option!         ";
  cin >> choice;
  cout << endl;

  switch (choice) {
  case 1:
    cout << "\t\t\t\t Please login here" << endl;
    cout << "\t\t\t\t Enter your email:";
    cin >> email;
    cout << endl;

    if (email == "admin1234@gmail.com" || email == "admin1234" ||
        email == "admin_me@gmail.com" || email == "admin_me") {
      cout << "\t\t\t\t Enter your password:";
      cin >> password;
      administrator();
    } else {
      cout << "\t\t\t\tInvalid email/password" << endl;
      login();
    }
    break;

  case 2:
    buyer();
    break;

  case 3:
    exit(0);

  default:
    cout << "\t\t\t\tPlease select 1-3 only!";
    goto start;
  }
}

void Shopping::administrator() {
choose:
  int choices;

  cout << "\t\t\t\t_______________________________________" << endl;
  cout << "\t\t\t\t                                       " << endl;
  cout << "\t\t\t\t             Administrator             " << endl;
  cout << "\t\t\t\t                                       " << endl;
  cout << "\t\t\t\t_______________________________________" << endl;
  cout << "\t\t\t\t                                       " << endl;
  cout << "\t\t\t\t|-------     1) Add Product    -------|" << endl;
  cout << "\t\t\t\t|-------     2) Modify Product -------|" << endl;
  cout << "\t\t\t\t|-------     3) Delete Product -------|" << endl;
  cout << "\t\t\t\t|-------     4) Back to main   -------|" << endl;
  cout << "\t\t\t\t                                       " << endl;
  cout << "\t\t\t\t     Please select the option!         ";
  cin >> choices;
  cout << endl;

  switch (choices) {
  case 1:
    add();
    break;

  case 2:
    edit();
    break;

  case 3:
    rem();
    break;

  case 4:
    login();
    break;

  default:
    cout << "\t\t\t\t Please select option 1-4 only!";
  }
  goto choose;
}

void Shopping::buyer() {
up:
  int choices;
  cout << endl;
  cout << "\t\t\t\t________________________________________" << endl;
  cout << "\t\t\t\t                                        " << endl;
  cout << "\t\t\t\t                  Buyer                 " << endl;
  cout << "\t\t\t\t                                        " << endl;
  cout << "\t\t\t\t________________________________________" << endl;
  cout << "\t\t\t\t                                        " << endl;
  cout << "\t\t\t\t|-------      1) Buy Product    -------|" << endl;
  cout << "\t\t\t\t|-------      2) Go Back        -------|" << endl;
  cout << "\t\t\t\t                                        " << endl;
  cout << "\t\t\t\t       Please select the option!        ";
  cin >> choices;
  cout << endl;

  switch (choices) {
  case 1:
    receipt();
    break;

  case 2:
    login();
    break;

  default:
    cout << "\t\t\t\tPlease choose 1-2 only!";
  }
  goto up;
}

void Shopping::add() {
addagain:
  fstream file;
  int c;
  float p;
  float d;
  string n;
  int token = 0;

  cout << "\t\t\t\t________________________________________" << endl;
  cout << "\t\t\t\t                                        " << endl;
  cout << "\t\t\t\t            Add new Product             " << endl;
  cout << "\t\t\t\t                                        " << endl;
  cout << "\t\t\t\t________________________________________" << endl;
  cout << "\t\t\t\t                                        " << endl;
  cout << "\t\t\t\t           ID of the product:           ";
  cin >> pid;
  cout << endl;
  cout << "\t\t\t\t           Product Name:                ";
  cin >> name;
  cout << endl;
  cout << "\t\t\t\t           Product Price:               ";
  cin >> price;
  cout << endl;
  cout << "\t\t\t\t           Discount on Product:         ";
  cin >> dis;
  cout << endl;

  file.open("database.txt", ios::in);

  if (!file) {
    file.open("database.txt", ios::app | ios::out);
    file << pid << " " << name << " " << price << " " << dis << " ";
    file.close();
  } else {
    file >> c >> n >> p >> d;

    while (!file.eof()) {
      if (c == pid)
        token++;
      file >> pid >> name >> price >> dis;
    }
  }

  if (token >= 1) {
    cout << "\t\t\t\tSame id of the product can't be added" << endl;
    goto addagain;
  } else {
    file.open("database.txt", ios::app | ios::out);
    file << pid << " " << name << " " << price << " " << dis << " ";
    file.close();
  }

  cout << "\t\t\t\tThanks for adding a new product!" << endl;
}

void Shopping::edit() {
  fstream data, data1;
  int pkey;
  int id;
  string n;
  float p;
  float d;
  int token = 0;

  cout << "\t\t\t\t________________________________________" << endl;
  cout << "\t\t\t\t                                        " << endl;
  cout << "\t\t\t\t             Modify Product             " << endl;
  cout << "\t\t\t\t                                        " << endl;
  cout << "\t\t\t\t________________________________________" << endl;
  cout << "\t\t\t\t                                        " << endl;
  cout << "\t\t\t\t           ID of the product:           ";
  cin >> pkey;
  cout << endl;
  data.open("database.txt", ios::in);

  if (!data) {
    cout << "\t\t\t\tFile doesn't exist" << endl;
  } else {
    data1.open("database1.txt", ios::app | ios::out);
    data >> pid >> name >> price >> dis;

    while (!data.eof()) {
      if (pkey == pid) {
        cout << "\t\t\t\tProduct id:";
        cin >> id;
        cout << endl;
        cout << "\t\t\t\tProduct name:";
        cin >> n;
        cout << endl;
        cout << "\t\t\t\tProduct Price:";
        cin >> p;
        cout << endl;
        cout << "\t\t\t\tDiscount on product:";
        cin >> d;
        cout << endl;
        token++;
      } else {
        data1 << pid << " " << name << " " << price << " " << dis << " ";
      }
      data >> pid >> name >> price >> dis;
    }
  }

  data.close();
  data1.close();

  if (token == 0) {
    cout << "\t\t\t\tSorry,Record not found!" << endl;
  }

  remove("database.txt");
  rename("database1.txt", "database.txt");
}

void Shopping::rem() {
  fstream data, data1;
  int token = 0;
  int pkey;

  cout << "\t\t\t\t________________________________________" << endl;
  cout << "\t\t\t\t                                        " << endl;
  cout << "\t\t\t\t             Delete Product             " << endl;
  cout << "\t\t\t\t                                        " << endl;
  cout << "\t\t\t\t________________________________________" << endl;
  cout << "\t\t\t\t                                        " << endl;
  cout << "\t\t\t\t           ID of the product:           " << endl;
  cin >> pkey;

  data.open("database.txt", ios::in);

  if (!data) {
    cout << "\t\t\t\tFile doesn't exist" << endl;
  } else {
    data1.open("database1.txt", ios::app | ios::out);
    data >> pid >> name >> price >> dis;

    while (!data.eof()) {
      if (pkey == pid) {
        cout << "\t\t\t\tProduct removed successfully!";
        token++;
      } else {
        data1 << pid << " " << name << " " << price << " " << dis;
      }
      data >> pid >> name >> price >> dis;
    }
  }
  data.close();
  data1.close();

  if (token == 0) {
    cout << "\t\t\t\tSorry,Record not found!" << endl;
  }

  remove("database.txt");
  rename("database1.txt", "database.txt");
}

void Shopping::list() {
  fstream data;
  data.open("database.txt", ios::in);

  cout << "\t__________________________________________________________________"
          "_______________"
       << endl;
  cout << "\t\t\t\tP_id\t\t\t\tP_name\t\t\t\tP_Price\t\t\t\tP_Discount" << endl;
  cout << "\t__________________________________________________________________"
          "_______________"
       << endl;
  data >> pid >> name >> price >> dis;

  while (!data.eof()) {
    cout << "\t" << pid << "\t" << name << "\t" << price << "\t" << dis << "\n";
    data >> pid >> name >> price >> dis;
  }
  data.close();
}

void Shopping::receipt() {
  fstream data;
  data.open("database.txt", ios::in);

  int aid[100];
  int aq[100];
  char choices;
  float amount = 0;
  float total = 0;
  float discount;
  int c = 0;

  if (!data) {
    cout << "\t\t\t\tFile doesn't exist" << endl;
  } else {
    data.close();
  change:
    list();
    cout << "\t\t\t\t________________________________________" << endl;
    cout << "\t\t\t\t                                        " << endl;
    cout << "\t\t\t\t                 Receipt                " << endl;
    cout << "\t\t\t\t                                        " << endl;
    cout << "\t\t\t\t________________________________________" << endl;
    cout << "\t\t\t\t                                        " << endl;
    do {
      cout << "\t\t\t\tEnter product id:";
      cin >> aid[c];
      cout << "\t\t\t\tEnter quantity for this product:";
      cin >> aq[c];

      for (int i = 0; i < c; i++) {
        if (aid[c] == aid[i]) {
          cout << "\t\t\t\tDuplicate product entered!" << endl;
          goto change;
        }
        c++;
        cout << "\t\t\t\tDo you want to add something more (y/n)?";
        cin >> choices;
      }

    } while (choices == 'y' || choices == 'Y');
  }

  cout << "\t\t\t\t****************************************" << endl;
  cout << "\t\t\t\t                                        " << endl;
  cout << "\t\t\t\t                Reciept                 " << endl;
  cout << "\t\t\t\t                                        " << endl;
  cout << "\t\t\t\t****************************************" << endl;
  cout << "\t\t\t\t                                        " << endl;

  for (int i = 0; i < c; i++) {

    data.open("database.txt", ios::in);
    data >> pid >> name >> price >> dis;

    while (!data.eof()) {
      if (pid == aid[i]) {
        amount = price * aq[i];
        discount = amount - (amount * dis / 100);
        total = amount + discount;
        cout << pid << " " << name << " " << price << " " << aq[i] << " "
             << amount << " " << dis << " " << endl;
      }
      data >> pid >> name >> price >> dis;
    }
  }
  data.close();
  cout << "\t\t\t\tTotal amount to be payed: " << total;
}

int main() {
  Shopping s;
  s.login();

  return 0;
}