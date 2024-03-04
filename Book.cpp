/*
    Implementation of Book class. Reads Book objects from a file, 
    and prints book descriptions in a given format.
*/


#include "Book.hpp"
    
    // write and document all methods in this file.
    /**
        Default constructor.
        Default-initializes all private members. 
        string variable, title, defaulted to blank ("")
        string variable, author, defaulted to blank ("")
        integer variable, ISBN, defaulted to zero
        long integer pointer, icon, defaulted to null pointer
        string vector, keyward, defaulted to empty ("")
        string variable, blurb, defaulted to blank ("")
    */
    Book::Book()
    : title_(""), author_(""), ISBN_(0), icon_(nullptr), 
    price_(0.0), keywords_(), blurb_("") {}

   /*
        Destructor
        since our icon variable is a pointer, we must delete it 
        dynamically when done 
   */
    Book::~Book()
    {
        delete[] icon_;
    }

    /*
        Copy constructor for the Book class.
        Constructs a new Book object by copying the data members from another Book object.
        Performs a deep copy of the icon_ array if rhs has a non-null icon_ array

        @Parame: rhs: Reference to the Book object to be copied
        @Returns: None
    */
    Book::Book(const Book& rhs) 
    : title_(rhs.title_), author_(rhs.author_), ISBN_(rhs.ISBN_), price_(rhs.price_), 
    keywords_(rhs.keywords_), blurb_(rhs.blurb_)
    {     
        if (rhs.icon_ != nullptr) {
            icon_ = new int[80];
            std::copy(rhs.icon_, rhs.icon_ + 80, icon_);
        } else {
            icon_ = nullptr;
        }
    }

    /*
        Copy assignment operator for the Book class.
        Assigns the data members of another Book object to this Book object.
        Performs deep copying of the icon_ array if rhs has a non-null icon_ array.

        @Param: rhs: Reference to the Book object whose data members are to be assigned to this object
        @Returns: Reference to this Book object after assignment
    */
    Book& Book::operator=(const Book& rhs)
    {
        if(this != &rhs) {
            delete[] icon_;
            title_ = rhs.title_;
            author_ = rhs.author_;
            price_ = rhs.price_;
            keywords_ = rhs.keywords_;
            blurb_ = rhs.blurb_;

            delete[] icon_;
            if (rhs.icon_ != nullptr) {
                icon_ = new int[80];
                std::copy(rhs.icon_, rhs.icon_ + 80, icon_);
            } else {
                icon_ = nullptr;
            }
        }
        return *this;
    }

    /*
        Move constructor for the Book class.
        Constructs a new Book object by moving the data members from another Book object (rhs).
        Performs a shallow move of the icon_ array from rhs to the new object.
        Sets rhs's icon_ pointer to nullptr to prevent resource duplication.

        @Param: rhs: Reference to the Book object to be moved from
        @Returns: None
    */
    Book::Book(Book&& rhs)
        : title_(std::move(rhs.title_)), author_(std::move(rhs.author_)), 
        ISBN_(rhs.ISBN_), icon_(rhs.icon_), price_(rhs.price_), keywords_(std::move(rhs.keywords_)), 
        blurb_(std::move(rhs.blurb_)) 
    {
        rhs.icon_ = nullptr;
    }

    /*
        Move assignment operator for the Book class
        Moves the data members of another Book object to this Book object
        Transfers ownership of resources from rhs to this object

        @Param: rhs: Reference to the Book object whose data members are to be moved to this object
        @Returns: Reference to this Book object after moving assignment
    */
    Book& Book::operator=(Book&& rhs)
    {
        if (this != &rhs) {
        title_ = std::move(rhs.title_);
        author_ = std::move(rhs.author_);
        ISBN_ = rhs.ISBN_;
        price_ = rhs.price_;
        keywords_ = std::move(rhs.keywords_);
        blurb_ = std::move(rhs.blurb_);

        delete[] icon_;

        icon_ = rhs.icon_;
        rhs.icon_ = nullptr;
    }
    return *this;
    }

    /*
        @return :   returns the private member title_
    */
    const std::string& Book::getTitle() const
    {
        return title_;
    }

    /*
        @param  : a string referring to title name
        @post   : sets the title_ private member to the value of the parameter
    */
    void Book::setTitle(const std::string& title)
    {
        title_ = title;
    }

    /*
        @return :   returns the private member author_
    */
    const std::string& Book::getAuthor() const
    {
        return author_;
    }

    /*
        @param  : a string referring to author name
        @post   : sets the author_ private member to the value of the parameter
    */
    void Book::setAuthor(const std::string& author)
    {
        author_ = author;
    }

    /*
        @return :   returns the private member ISBN_
    */
    long long int Book::getISBN() const
    {
        return ISBN_;
    }

    /*
        @param  : a string referring to author name
        @post   : sets the author_ private member to the value of the parameter
    */
    void Book::setISBN(long long int ISBN)
    {
        ISBN_ = ISBN;
    }

    /*
        @return :   returns the private member icon_
    */
    const int* Book::getIcon() const
    {
        return icon_;
    }

    /*
        @param  : an integer pointer, icon that represents  a small bitmap, 
                    so it consists of 80 integers between 0 and 255
        @post   : sets the icon_ private member to the value of the parameter
    */
    void Book::setIcon(int* icon)
    {
        delete[] icon_;
        icon_ = new int[80];
        for (int i = 0; i < 80; ++i) {
            icon_[i] = icon[i];
    }
    }

    /*
        @return :   returns the private member price_
    */
    float Book::getPrice() const
    {
        return price_;
    }

    /*
        @param  : a float referring to the price of the book
        @post   : sets the price_ private member to the value of the parameter
    */
    void Book::setPrice(float price)
    {
        price_ = price;
    }

    /*
        @return :   returns the private member keywords_
    */
    const std::vector<std::string>& Book::getKeywords() const
    {
        return keywords_;
    }

    /*
        @param  : a string of vectors consisting of keywords
        @post   : sets the keywords_ private member to the value of the parameter
    */
    void Book::setKeywords(const std::vector<std::string>& keywords)
    {
        keywords_ = keywords;
    }

    /*
        @return :   returns the private member blurb_
    */
    const std::string& Book::getBlurb() const
    {
        return blurb_;
    }

    /*
        @param  : a string variable representing a book description
        @post   : sets the blurb_ private member to the value of the parameter
    */
    void Book::setBlurb(const std::string& blurb)
    {
        blurb_ = blurb;
    }
    
    /*
        Print() takes all components of book and prints out the order associated to the format:
        
        Title: "Seikou."
        Author: Hildred Billings
        ISBN: 8080124750
        Icon: 155 198 103 166 240 32 127 245 94 139 114 62 234 184 86 203 124 99 47 204 191 233 116 198 175 72 167 248 81 20 0 113 29 42 92 131 118 99 166 154 170 54 48 100 89 49 127 34 32 27 122 38 88 82 26 78 136 219 157 134 118 140 48 184 133 212 194 198 166 246 153 24 220 173 223 24 231 199 83 14 
        Price: $30.07
        Keywords: Spanish Literature, Magical Realism, Romanian Literature
        Blurb: For over twenty years Reina has sexually celebrated the women around her with a reverence only tolerated by her wife, Aiko. But when Reina misinterprets the fluidity of their open relationship, she's backed into a corner where her gender dysphoria reigns supreme. In order to salvage her marriage, she may have to reanalyze the way she views the world, her life, and her experiences.,Just when she thinks she's figured her spouse out, Aiko faces an unexpected transgression. Can she forgive her? Or will love finally give way to the fatigue that accompanies being with someone like Reina? A sick mother and unsympathetic sister are not helping Aiko's dilemma.,Even the most passionate relationships sometimes fall asunder to "seikou," the sexual character at the core of one's identity. Will Reina and Aiko reunite with stronger hearts, or is it finally time to go their separate ways? And if they do split up, who will help them pick up the pieces - the stoic therapist, the desperate socialite, or the young couple who initiated this mess to begin with?
    */
    void Book::print() const
    {
        std::cout << "Title: "<< title_ << "\n";
        std::cout << "Author: " << author_ << "\n";
        std::cout << "ISBN: " << ISBN_ << "\n";
        std::cout << "Icon: ";
        if (icon_ != nullptr) {
            for (int i = 0; i < 79; ++i) {
                std::cout << icon_[i] << " ";
            }
            std::cout << icon_[79];
        }
        std::cout << std::endl;
        std::cout << "Price: $" << std::fixed << std::setprecision(2) << price_ << std::endl;
        std::cout << "Keywords: ";
        for (size_t i = 0; i < keywords_.size(); ++i) {
            std::cout << keywords_[i];
            if (i < keywords_.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
        std::cout << "Blurb: " << blurb_ << std::endl;
    }
