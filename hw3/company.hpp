struct Company {
  Company *parent;   // the parent company, or nullptr if it has no parent
  Company *merge1, *merge2;
  /* the subcompanies that were merged to obtain this company, or
     nullptr if this is a 1-student company */

  Company ()
  { parent = nullptr; merge1 = nullptr; merge2 = nullptr; }
  Company (Company *m1, Company *m2)
  { parent = nullptr; merge1 = m1; merge2 = m2; }
};

class CompanyTracker {
 public:
  CompanyTracker (int n);
  // initializes the tracker with n students and their 1-person companies

  ~CompanyTracker (); // deallocates all dynamically allocated memory

  void merge (int i, int j);
  /* Merges the largest companies containing students i and j,
     according to the rules described above.
     That is, it generates a new Company object which will
     become the parent company of the largest companies currently
     containing students i and j.
     If i and j already belong to the same company (or are the same),
     merge doesn't do anything.
     If either i or j are out of range, merge doesn't do anything. */

  void split (int i);
  /* Splits the largest company that student i belongs to,
     according to the rules described above.
     That is, it deletes that Company object, and makes sure that
     the two subcompanies have no parent afterwards.
     If i's largest company is a 1-person company, split doesn't do anything.
     If i is out of range, split doesn't do anything. */

  bool inSameCompany (int i, int j);
  /* Returns whether students i and j are currently in the same company.
     Returns true if i==j.
     Returns false if i or j (or both) is out of range. */

 private:
  int numCompanies;  // the number of companies you are tracking

  Company** companies;
  /* an array (allocated once in the constructor)
     to keep pointers to all the 1-person companies.
     Will not contain the merged companies. */

  /* Feel free to add private helper functions as you see fit.
     In particular, you may want a function to find the largest company
     that a student i is part of. */
};
