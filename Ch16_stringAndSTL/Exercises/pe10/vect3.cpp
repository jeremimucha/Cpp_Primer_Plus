// vect3.cpp -- using STL functions
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
using std::unique_ptr;

struct Review
{
    std::string title;
    int rating;
    double price;
    Review() { }
    Review(const Review& r)
        : title(r.title), rating(r.rating), price(r.price) { }
};


bool operator<(const Review& r1, const Review& r2);
// bool worseThan(const Review& r1, const Review& r2);
bool worseThan(const unique_ptr<Review>& pr1, const unique_ptr<Review>& pr2);
bool FillReview(Review& rr);
// void ShowReview(const Review& rr);
void ShowReview(const unique_ptr<Review>& pr);

int main()
{
    using namespace std;

    // vector<Review> books;
    vector<unique_ptr<Review>> books;
    // Review temp;
    for(Review temp;
        FillReview(temp);)
        books.push_back(unique_ptr<Review>(new Review(temp)));
    // while(FillReview(temp)){
    //     books.push_back(temp);
    // }
    if(books.size() > 0){
        cout << "Thank you. You entered the following "
             << books.size() << " ratings:\n"
             << "Rating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);
        
        // sort(books.begin(), books.end());
        // cout << "Sorted by title:\nRating\tBook\n";
        // for_each(books.begin(), books.end(), ShowReview);

        sort(books.begin(), books.end(), worseThan);
        cout << "Sorted by rating:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        random_shuffle(books.begin(), books.end());
        cout << "After shuffling:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);
    }
    else
        cout << "No entries. ";
    cout << "Bye.\n";
    return 0;
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

bool worseThan(const unique_ptr<Review>& pr1, const unique_ptr<Review>& pr2)
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
    // get rid of rest of input line
    while(std::cin.get() != '\n')
        ;
    return true;
}

// void ShowReview(const Review& rr)
// {
//     std::cout << rr.rating << '\t' << rr.title << std::endl;
// }

void ShowReview(const unique_ptr<Review>& pr)
{
    std::cout << pr->rating << '\t' << pr->title << std::endl;
}
