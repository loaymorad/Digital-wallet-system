# 💳 Digital Wallet System (C++)

A **console-based digital wallet system** implemented in C++.  
This project simulates a simple wallet where users can **register, log in, send/request money, and view transaction history**.  
Admins can **manage users and transactions**.  
All data is **persistent** using file storage (`users.txt`, `transactions.txt`).  

---

## 📌 Features

### 👤 Users
- Register and Login  
- View balance  
- Send money to other users  
- Request money from other users  
- View transaction history (using **stack**)  
- Edit profile (change password)  

### 👨‍💻 Admins
- Login with admin credentials  
- View all registered users  
- Suspend / Reactivate users  
- Adjust user balances  
- View all transactions  

### 🗄️ Database
- Uses **file system storage** (`users.txt`, `transactions.txt`)  
- Users stored with format:  `username$password$balance$suspended`
- Transactions stored with format:  `sender$receiver$amount`


---

## 🛠️ Technologies & Data Structures

- **Language**: C++  
- **Core STL Containers**:
- `stack<Transaction>` → Transaction history (LIFO)  
- `queue<Transaction>` → Pending money requests (FIFO)  
- `unordered_map<string, User>` → Fast user database (O(1) lookup)  
- `map<string, vector<Transaction>>` → Transactions storage  
