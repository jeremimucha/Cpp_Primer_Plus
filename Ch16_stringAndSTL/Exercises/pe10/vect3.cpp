// vect3.cpp -- using STL functions
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <memory>
using std::shared_ptr;


struct Review
{
    std::string title;
    int rating;
    double price;
    Review() { }
    Review(const Review& r)
        : title(r.title), rating(r.rating), price(r.price) { }
    friend bool operator<(const shared_ptr<Review>& pr1, const shared_ptr<Review>& pr2);
    friend std::ostream& operator<<(std::ostream& os, const shared_ptr<Review>& pr);
    static bool sortby_title(const shared_ptr<Review>& a, const shared_ptr<Review>& b);
    static bool sortby_rating(const shared_ptr<Review>& a, const shared_ptr<Review>& b);
    static bool sortby_price(const shared_ptr<Review>& a, const shared_ptr<Review>& b);
};


bool operator<(const Review& r1, const Review& r2);
// bool worseThan(const Review& r1, const Review& r2);
bool worseThan(const shared_ptr<Review>& pr1, const shared_ptr<Review>& pr2);
bool FillReview(Review& rr);
// void ShowReview(const Review& rr);
void ShowReview(const shared_ptr<Review>& pr);

int main()
{
    using namespace std;

    // vector<Review> books;
    vector<shared_ptr<Review>> books;
    // Review temp;
    for(Review temp;
        FillReview(temp);)
        books.push_back(shared_ptr<Review>(new Review(temp)));
    // while(FillReview(temp)){
    //     books.push_back(temp);
    // }
    if(books.size() > 0){
        vector<shared_ptr<Review>> bks(books.begin(), books.end());
        cout << "Thank you. You entered " << books.size() << " books.\n";
        const char* msg = "Please select how you'd like the data displayed:\n"
             "1: Original order\t2: Alphabetical order\n"
             "3: By rating (increasing)\t4: By rating (decreasing)\n"
             "5: By price (increasing)\t6: By price (decreasing)\n"
             "q: quit\n";
        string choices("123456q");
        char choice;
        cout << msg;
        while(cout << ">> " && cin >> choice){
            if(choices.find(choice) == string::npos){
                cout << "Invalid choice. Please try again.\n";
                cout << msg;
                continue;
            }
            if(choice == 'q')
                break;
            cout << "Title\tRating\tPrice\n";
            switch(choice){
                case '1':
                    for(shared_ptr<Review>& pr : books) ShowReview(pr);
                    break;
                case '2':
                    std::sort(bks.begin(), bks.end(), Review::sortby_title);
                    for(shared_ptr<Review>& pr : bks) ShowReview(pr);
                    break;
                case '3':
                    std::sort(bks.begin(), bks.end(), Review::sortby_rating);
                    for(auto& b : bks) cout << b;
                    break;
                case '4':
                    std::sort(bks.begin(), bks.end(), Review::sortby_rating);
                    for(auto iter=bks.rbegin(); iter!=bks.rend(); ++iter)
                        cout << *iter;
                    break;
                case '5':
                    std::sort(bks.begin(), bks.end(), Review::sortby_price);
                    for(auto& b : bks) cout << b;
                    break;
                case '6':
                    std::sort(bks.begin(), bks.end(), Review::sortby_price);
                    for(vector<shared_ptr<Review>>::const_reverse_iterator iter=bks.rbegin();
                        iter!=bks.rend(); ++iter)
                        cout << *iter;
                    break;
            }
        }
    }
    else
        cout << "No entries. ";
    cout << "Bye.\n";
    return 0;
}

std::ostream& operator<<(std::ostream& os, const shared_ptr<Review>& pr)
{
    return os << pr->rating << '\t' << pr->title << '\t' << pr->price << std::endl;
}

bool operator<(const shared_ptr<Review>& pr1, const shared_ptr<Review>& pr2)
{
    if(pr1->title < pr2->title)
        return true;
    else if(pr1->rating < pr2->rating)
        return (pr1->title == pr2->title && pr1->rating < pr2->rating);
    else
        return (pr1->title == pr2->title && pr1->rating == pr2->rating && pr1->price < pr2->price);
}

bool operator<(const Review& r1, const Review& r2)
{
    if(r1.title < r2.title)
        return true;
    else if(r1.rating < r2.rating)
        return (r1.title == r2.title && r1.rating < r2.rating);
    else
        return (r1.title == r2.title && r1.rating == r2.rating && r1.price < r2.price);
}

// bool worseThan(const Review& r1, const Review& r2)
// {
//     return r1.rating < r2.rating;
// }

bool worseThan(const shared_ptr<Review>& pr1, const shared_ptr<Review>& pr2)
{
    return pr1->rating < pr2->rating;
}

bool FillReview(Review& rr)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin, rr.title);
    if(rr.title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;
    if(!std::cin)
        return false;
    std::cout << "Enter book price: ";
    std::cin >> rr.price;
    if(!std::cin)
        return false;
    // get rid of rest of input line
    while(std::cin.get() != '\n')
        ;
    return true;
}

// void ShowReview(const Review& rr)
// {
//     std::cout << rr.rating << '\t' << rr.title << std::endl;
// }

void ShowReview(const shared_ptr<Review>& pr)
{
    std::cout << pr->rating << '\t' << pr->title << '\t' << pr->price << std::endl;
}


bool Review::sortby_title(const shared_ptr<Review>& a, const shared_ptr<Review>& b)
{
    return a->title < b->title;
}

bool Review::sortby_rating(const shared_ptr<Review>& a, const shared_ptr<Review>& b)
{
    return a->rating < b->rating;
}

bool Review::sortby_price(const shared_ptr<Review>& a, const shared_ptr<Review>& b)
{
    return a->price < b->price;
}