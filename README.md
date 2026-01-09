# Banking System with User Hierarchy

A C++ banking system implementation demonstrating object-oriented programming principles, inheritance, polymorphism, and exception handling. The system supports different user types with varying withdrawal capabilities.

##Features

- **User Hierarchy**: Different user types (Regular and Premium) with unique capabilities
- **Bank Account Management**: Secure balance tracking and transaction processing
- **Polymorphic Withdrawals**: Virtual function implementation for user-specific withdrawal rules
- **Exception Handling**: Comprehensive error handling for invalid operations
- **Memory Management**: Proper resource cleanup using destructors
- **Loan Facility**: Premium users can withdraw beyond balance using approved loan limits

## 🗺️ Class Diagram

```
┌─────────────────┐
│   BankAccount   │
├─────────────────┤
│ - userName: str │
│ - balance: double│
├─────────────────┤
│ + BankAccount() │
│ + getBal()      │
│ + debit()       │
│ + ~BankAccount()│
└────────┬────────┘
         │
         │ contains
         ▼
┌─────────────────┐
│      User       │
├─────────────────┤
│ - name: str     │
│ - account: ptr  │
├─────────────────┤
│ + User()        │
│ + withdraw()    │◄───┐
│ + ~User()       │    │
└────────┬────────┘    │
         │             │
         │ inherits    │
         ▼             │
┌─────────────────┐    │
│  RegularUser    │    │
├─────────────────┤    │
│ + RegularUser() │    │
│ + withdraw()    │────┘
│ + ~RegularUser()│
└─────────────────┘
         ▲
         │
┌─────────────────┐
│  PremiumUser    │
├─────────────────┤
│ - loanLimit: double│
├─────────────────┤
│ + PremiumUser() │
│ + withdraw()    │────┐
│ + ~PremiumUser()│    │
└─────────────────┘    │
                       │
                 (Polymorphic Function)
```

## Class Structure

### 1. **BankAccount Class**
Core banking entity that manages user balances.

**Responsibilities:**
- Store and validate account balance
- Process debit transactions
- Ensure balance integrity

**Key Methods:**
- `BankAccount(double balance)` - Constructor with balance validation
- `double getBal()` - Returns current balance
- `void debit(double amount)` - Deducts amount from balance
- `~BankAccount()` - Destructor for cleanup

### 2. **User Class (Abstract)**
Base class for all user types with pure virtual function.

**Responsibilities:**
- Define common user interface
- Manage associated BankAccount
- Provide abstraction for withdrawal operations

**Key Methods:**
- `User(string name, double balance)` - Initializes user with account
- `virtual void withdraw(double amount) = 0` - Pure virtual function
- `virtual ~User()` - Virtual destructor for proper cleanup

### 3. **RegularUser Class**
Standard banking user with basic withdrawal capabilities.

**Withdrawal Rules:**
- Can only withdraw up to current balance
- No overdraft or loan facilities

### 4. **PremiumUser Class**
Premium banking user with extended financial services.

**Additional Features:**
- `double loanLimit` - Approved loan amount
- Can withdraw beyond balance using loan limit
- Loan amount reduces available loan limit

**Withdrawal Logic:**
1. If amount ≤ balance: Deduct from balance
2. If amount ≤ (balance + loanLimit): Use combination of balance and loan
3. Otherwise: Throw exception

## 📝 Usage Example

```cpp
// Creating a regular user
User* regular = new RegularUser("John", 5000);
regular->withdraw(3000);  // Success
regular->withdraw(3000);  // Throws exception - insufficient funds

// Creating a premium user
User* premium = new PremiumUser("Sarah", 10000, 20000);
premium->withdraw(25000);  // Uses 10000 balance + 15000 loan
premium->withdraw(10000);  // Uses remaining 5000 loan limit
```

## Exception Handling

The system implements comprehensive exception handling:

1. **Invalid Balance**: Negative initial balance throws exception
2. **Insufficient Funds**: Regular users attempting to withdraw more than balance
3. **Loan Limit Exceeded**: Premium users exceeding combined balance + loan limit

**Example Error Messages:**
```
"Balance can't be negative. Please try again"
"Withdraw denied: Typed Amount is greater than balance"
"Withdraw denied: (loan limit exceed)"
```

## Memory Management

### Key Design Patterns:
1. **RAII (Resource Acquisition Is Initialization)**: Resources allocated in constructors, freed in destructors
2. **Virtual Destructors**: Ensure proper cleanup of derived classes
3. **Ownership Semantics**: Each User owns its BankAccount

### Memory Flow:
```
RegularUser/PremiumUser Construction:
1. User constructor called
2. BankAccount allocated with new
3. Derived class constructor completes

Destruction:
1. ~RegularUser/~PremiumUser() called
2. ~User() called (deletes BankAccount)
3. ~BankAccount() called
```

### Code Improvements:
- Implement smart pointers for automatic memory management
- Add copy constructors and assignment operators
- Implement serialization for object persistence
- Add unit tests using Google Test framework

## Testing

The system includes built-in test cases:
1. Regular user normal withdrawal
2. Regular user overdraft attempt (throws exception)
3. Premium user withdrawal within balance
4. Premium user withdrawal using loan facility
5. Premium user exceeding total credit limit (throws exception)

## Learning Outcomes

This project demonstrates:
- **OOP Principles**: Encapsulation, Inheritance, Polymorphism
- **Memory Management**: Proper use of new/delete and destructors
- **Exception Safety**: Robust error handling
- **Design Patterns**: Template Method pattern via virtual functions
- **Resource Management**: Ownership and lifetime management
