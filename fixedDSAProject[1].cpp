#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
using namespace std;

// Global variables for login
char choice;
string userName;
string userPassword;

/*
Orders -- Module
Implemented and managed through graphs
*/
struct Order
{
    // Credentials
    string userName;
    string userPassword;
    string address;

    // From inventory
    string itemName;
    int quantity;
    float price;

    // Edge attributes
    int src;
    int dest;
    int wt;

    // Constructor
    Order(string userName, string userPassword, string address, string itemName, int quantity, float price, int src, int dest, int wt)
        : userName(userName), userPassword(userPassword), address(address), itemName(itemName), quantity(quantity), price(price), src(src), dest(dest), wt(wt) {}
};

vector<Order> graph[29];

void createOrder(vector<Order> graph[], const Order &order)
{
    graph[order.src].push_back(order);
}

void printGraph(vector<Order> graph[], const Order &order)
{
    queue<Order> queue;
    bool visited[29][29] = {false}; // 2D array to mark visited orders

    queue.push(order);

    while (!queue.empty())
    {
        Order currentOrder = queue.front();
        queue.pop();

        if (!visited[currentOrder.src][currentOrder.dest])
        {
            // Print order details
            cout << "Customer name : " << currentOrder.userName << endl
                 << "Customer password : " << currentOrder.userPassword << endl
                 << "Customer Address : " << currentOrder.address << endl
                 << "Item name : " << currentOrder.itemName << endl
                 << "Item Quantity : " << currentOrder.quantity << endl
                 << "Item Price : " << currentOrder.price << endl
                 << "Source vertex : " << currentOrder.src << endl
                 << "Destination vertex : " << currentOrder.dest << endl
                 << "Distance from src-dest : " << currentOrder.wt << endl;
            cout << endl;

            visited[currentOrder.src][currentOrder.dest] = true;

            // Add connected orders to the queue
            for (const auto &neighbor : graph[currentOrder.src])
            {
                queue.push(neighbor);
            }
            for (const auto &neighbor : graph[currentOrder.dest])
            {
                queue.push(neighbor);
            }
        }
    }
}
void searchOrder(vector<Order> graph[], string userName, string userPassword)
{
    queue<Order> q;
    bool visited[29][29] = {false};

    for (int i = 0; i < 29; ++i)
    {
        for (auto &order : graph[i])
        {
            q.push(order);
        }
    }

    while (!q.empty())
    {
        Order currentOrder = q.front();
        q.pop();

        if (!visited[currentOrder.src][currentOrder.dest])
        {
            visited[currentOrder.src][currentOrder.dest] = true;

            if (currentOrder.userName == userName && currentOrder.userPassword == userPassword)
            {
                cout << "Customer Name: " << currentOrder.userName << endl
                     << "Customer Password: " << currentOrder.userPassword << endl
                     << "Customer Address: " << currentOrder.address << endl
                     << "Item Name: " << currentOrder.itemName << endl
                     << "Item Quantity: " << currentOrder.quantity << endl
                     << "Item Price: " << currentOrder.price << endl
                     << "Source Vertex: " << currentOrder.src << endl
                     << "Destination Vertex: " << currentOrder.dest << endl
                     << "Distance from Src-Dest: " << currentOrder.wt << endl
                     << endl;
            }
        }
    }
}

struct Pair
{
    int node;
    int dist;

    Pair(int node, int dist) : node(node), dist(dist) {}

    bool operator<(const Pair &other) const
    {
        return this->dist > other.dist; // Min-heap based on distance
    }
};

void dijkstra(vector<Order> graph[], Order src)
{
    priority_queue<Pair> pq;
    int distance[29];
    bool visited[29] = {false};

    for (int i = 0; i < 29; ++i)
    {
        distance[i] = numeric_limits<int>::max();
    }

    distance[src.src] = 0;
    pq.push(Pair(src.src, 0));

    while (!pq.empty())
    {
        Pair current = pq.top();
        pq.pop();

        if (!visited[current.node])
        {
            visited[current.node] = true;

            for (const auto &order : graph[current.node])
            {
                int u = order.src;
                int v = order.dest;
                int weight = order.wt;

                if (distance[u] + weight < distance[v])
                {
                    distance[v] = distance[u] + weight;
                    pq.push(Pair(v, distance[v]));
                }
            }
        }
    }

    cout << "Shortest paths from warehouse to all delivery points:\n";
    for (int i = 0; i < 29; ++i)
    {
        if (distance[i] == numeric_limits<int>::max())
        {
            cout << "Vertex " << i << " is unreachable.\n";
        }
        else
        {
            cout << "Vertex " << i << " : " << distance[i] << " km\n";
        }
    }
}
/*
Login -- Module
Implemented and managed through HashTable
*/
struct hashTable
{
    string userName; // key
    string userPassword;
};

const int hashTableSize = 29;
hashTable table[hashTableSize];

// Initialize the hash table
void initHashTable()
{
    for (int i = 0; i < hashTableSize; i++)
    {
        table[i].userName = "";
        table[i].userPassword = "";
    }
}

// Hash function to compute the index
int hashFunction(string userName)
{
    int key = 0;
    for (char ch : userName)
    {
        key += static_cast<int>(ch);
    }
    return key % hashTableSize;
}

// Insert a record into the hash table
void insertRecord(string userName, string userPassword)
{
    int indexOfKey = hashFunction(userName);

    // Linear probing to handle collisions
    for (int i = 0; i < hashTableSize; i++)
    {
        int probeIndex = (indexOfKey + i) % hashTableSize;
        if (table[probeIndex].userName == "")
        {
            table[probeIndex].userName = userName;
            table[probeIndex].userPassword = userPassword;
            return;
        }
    }
    cout << "Hash table is full. Cannot insert record.\n";
}

// Search for a record in the hash table
bool searchRecord(string userName, string userPassword)
{
    int indexOfKey = hashFunction(userName);

    // Linear probing to search
    for (int i = 0; i < hashTableSize; i++)
    {
        int probeIndex = (indexOfKey + i) % hashTableSize;
        if (table[probeIndex].userName == userName)
        {
            if (table[probeIndex].userPassword == userPassword)
            {
                cout << "Search was successful: " << table[probeIndex].userName << " - " << table[probeIndex].userPassword << "\n";
                return true;
            }
            else
            {
                cout << "Incorrect password for user: " << userName << "\n";
                return false;
            }
        }
        if (table[probeIndex].userName == "")
            break; // Stop searching if an empty slot is found
    }
    cout << "User not found.\n";
    return false;
}

// Print the hash table to the console
void printHashTable()
{
    for (int i = 0; i < hashTableSize; i++)
    {
        cout << i << " ----- " << table[i].userName << " " << table[i].userPassword << "\n";
    }
}

// Write the hash table contents to a file
void printHashTableInFile()
{
    ofstream MyFile("customer_details.txt");
    if (!MyFile)
    {
        cout << "Error opening file for writing.\n";
        return;
    }

    for (int i = 0; i < hashTableSize; i++)
    {
        MyFile << i << " ----- " << table[i].userName << " " << table[i].userPassword << "\n";
    }
    MyFile.close();
    cout << "Hash table successfully written to file.\n";
}
/*
Inventory -- Module
Implemented and managed through BST
*/
struct item
{
    string itemName;
    int availableQuantity;
    float perUnitPrice;
    item *left;
    item *right;
};

// Create a new node
item *createNode(string itemName, int availableQuantity, float perUnitPrice)
{
    item *newNode = new item();
    newNode->itemName = itemName;
    newNode->availableQuantity = availableQuantity;
    newNode->perUnitPrice = perUnitPrice;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert an item into the BST
item *insertItem(item *root, string itemName, int availableQuantity, float perUnitPrice)
{
    if (root == NULL)
    {
        return createNode(itemName, availableQuantity, perUnitPrice);
    }
    if (perUnitPrice < root->perUnitPrice)
    {
        root->left = insertItem(root->left, itemName, availableQuantity, perUnitPrice);
    }
    else
    {
        root->right = insertItem(root->right, itemName, availableQuantity, perUnitPrice);
    }
    return root;
}

// Find the node with the minimum value in the BST
item *findMin(item *root)
{
    while (root && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

// Find the node with the maximum value in the BST
item *findMax(item *root)
{
    while (root && root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

// Search for an item in the BST
item *searchItem(item *root, string itemName, float key)
{
    if (root == NULL || (root->perUnitPrice == key && root->itemName == itemName))
    {
        return root;
    }
    if (key < root->perUnitPrice)
    {
        return searchItem(root->left, itemName, key);
    }
    return searchItem(root->right, itemName, key);
}

// Remove an item from the BST
item *removeItem(item *root, float price)
{
    if (root == NULL)
    {
        return root;
    }
    if (price < root->perUnitPrice)
    {
        root->left = removeItem(root->left, price);
    }
    else if (price > root->perUnitPrice)
    {
        root->right = removeItem(root->right, price);
    }
    else
    {
        if (root->left == NULL)
        {
            item *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            item *temp = root->left;
            delete root;
            return temp;
        }
        item *temp = findMin(root->right);
        root->itemName = temp->itemName;
        root->availableQuantity = temp->availableQuantity;
        root->perUnitPrice = temp->perUnitPrice;
        root->right = removeItem(root->right, temp->perUnitPrice);
    }
    return root;
}

// Preorder traversal (Root -> Left -> Right)
void preorderTraversal(item *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << "Item Name: " << root->itemName << endl;
    cout << "Available Quantity: " << root->availableQuantity << endl;
    cout << "Per Unit Price: " << root->perUnitPrice << endl;
    cout << "--------------------------" << endl;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Inorder traversal (Left -> Root -> Right)
void inorderTraversal(item *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << "Item Name: " << root->itemName << endl;
    cout << "Available Quantity: " << root->availableQuantity << endl;
    cout << "Per Unit Price: " << root->perUnitPrice << endl;
    cout << "--------------------------" << endl;
    inorderTraversal(root->right);
}

// Postorder traversal (Left -> Right -> Root)
void postorderTraversal(item *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << "Item Name: " << root->itemName << endl;
    cout << "Available Quantity: " << root->availableQuantity << endl;
    cout << "Per Unit Price: " << root->perUnitPrice << endl;
    cout << "--------------------------" << endl;
}
void placeOrder(item *itemToBuy)
{
    if (itemToBuy == nullptr)
    {
        cout << "Error: Item not found in inventory." << endl;
        return;
    }

    int itemQuantity;
    float totalPrice;
    string customerAddress;
    int src, dest, wt;

    // Get the item quantity from the user
    cout << "Enter Quantity: ";
    cin >> itemQuantity;

    if (itemQuantity <= 0)
    {
        cout << "-> Invalid quantity. Please enter a positive number." << endl;
        return;
    }

    if (itemQuantity > itemToBuy->availableQuantity)
    {
        cout << "-> Insufficient stock. Only " << itemToBuy->availableQuantity
             << " items are available." << endl;
        return;
    }

    // Calculate total price
    totalPrice = itemToBuy->perUnitPrice * itemQuantity;

    // Get other order details
    cout << "Enter your residential address: ";
    cin.ignore(); // Clear input buffer
    getline(cin, customerAddress);

    cout << "Enter source vertex: ";
    cin >> src;

    cout << "Enter destination vertex: ";
    cin >> dest;

    cout << "Enter distance from source to destination: ";
    cin >> wt;

    if (wt <= 0)
    {
        cout << "-> Invalid distance. Please enter a positive number." << endl;
        return;
    }

    // Create the order
    Order order = Order(userName, userPassword, customerAddress, itemToBuy->itemName,
                        itemQuantity, totalPrice, src, dest, wt);

    createOrder(graph, order); // Add the order to the graph

    // Generate receipt
    cout << "-> Your order was successfully placed. A receipt has been generated..." << endl;

    ofstream receiptFile("order_receipt.txt");
    if (receiptFile.is_open())
    {
        receiptFile << "============================================" << endl;
        receiptFile << "              Order Receipt                 " << endl;
        receiptFile << "============================================" << endl;
        receiptFile << "Customer Name        : " << userName << endl;
        receiptFile << "Customer Address     : " << customerAddress << endl;
        receiptFile << "Item Name            : " << itemToBuy->itemName << endl;
        receiptFile << "Item Quantity        : " << itemQuantity << endl;
        receiptFile << "Total Price          : " << totalPrice << endl;
        receiptFile << "Source Vertex        : " << src << endl;
        receiptFile << "Destination Vertex   : " << dest << endl;
        receiptFile << "Distance (src-dest)  : " << wt << " units" << endl;
        receiptFile << "============================================" << endl;
        receiptFile.close();
        cout << "-> Receipt saved as 'order_receipt.txt'." << endl;
    }
    else
    {
        cout << "-> Error: Unable to generate the receipt file." << endl;
    }

    // Update inventory
    itemToBuy->availableQuantity -= itemQuantity;
    cout << "-> Remaining stock of " << itemToBuy->itemName << ": "
         << itemToBuy->availableQuantity << endl;
}
void parcelDistributionSystem()
{
    // Predefined Items
    item *root = createNode("Travel Backpack", 2500, 5700);
    insertItem(root, "Eye Mask", 4000, 2100);
    insertItem(root, "Water Bottle", 3000, 270);

    // Predefined Customers
    insertRecord("Raza", "1234");
    insertRecord("Junaid", "981");

    // Predefined Orders
    Order order1 = Order("Raza", "1234", "abc street", "Water Bottle", 10, 2700, 0, 1, 12);
    Order order2 = Order("Junaid", "981", "block12", "Eye Mask", 12, 25200, 0, 5, 12);
    createOrder(graph, order1);
    createOrder(graph, order2);

    // Login menu
loginMenu:
    cout << "============================================\n"
         << "          Parcel Distribution System         \n"
         << "============================================\n";
    cout << "1. Login as Admin" << endl
         << "2. Login as Customer" << endl;

    char choice;
    cin >> choice;

    string itemName;
    int itemQuantity;
    float price;

    if (choice == '1')
    {
        // Admin
        cout << "============================================\n"
             << "               Login as Admin                \n"
             << "============================================\n";
        cout << "Enter username: ";
        cin >> userName;
        cout << "Enter password: ";
        cin >> userPassword;

        if (userName == "admin123" && userPassword == "admin123")
        {
            cout << "-> Login successful...\n"
                 << endl;

        adminMenu:
            cout << "--------------- Inventory --------------- " << endl;
            cout << "1. Add An Item" << endl
                 << "2. Search An Item" << endl
                 << "3. Remove An Item" << endl
                 << "4. Display Inventory" << endl
                 << "5. Show product with smallest price" << endl
                 << "6. Show product with largest price\n"
                 << endl;
            cout << "---------------- Customers --------------- " << endl;
            cout << "7. Print customer details" << endl
                 << "8. Search customer\n"
                 << endl;
            cout << "---------------- Routes ----------------- " << endl;
            cout << "9. Display orders" << endl
                 << "0. Deliver orders\n"
                 << endl;

            cin >> choice;

            if (choice == '1')
            {
                // Add item in inventory
                cout << "Enter Product Name: ";
                cin.ignore();
                getline(cin, itemName);
                cout << "Enter Product Quantity: ";
                cin >> itemQuantity;
                cout << "Enter Price: ";
                cin >> price;

                insertItem(root, itemName, itemQuantity, price);
                cout << "Item was added successfully!" << endl;
                cout << "============================================\n"
                     << "            Available Items                 \n"
                     << "============================================\n";
                inorderTraversal(root);

                cout << "1. Admin menu" << endl
                     << "2. Main menu" << endl;
                cin >> choice;

                if (choice == '1')
                {
                    goto adminMenu;
                }
                else if (choice == '2')
                {
                    goto loginMenu;
                }
                else
                {
                    cout << "Invalid option, returning to Admin menu..." << endl;
                    goto adminMenu;
                }
            }
            else if (choice == '2')
            {
                // Search item from inventory
                cout << "============================================\n"
                     << "                Search Item                 \n"
                     << "============================================\n";
                cout << "Enter Item Name: ";
                cin.ignore();
                getline(cin, itemName);
                cout << "Enter Price: ";
                cin >> price;

                item *foundItem = searchItem(root, itemName, price);

                if (foundItem)
                {
                    cout << "============================================\n"
                         << "                Product Found               \n"
                         << "============================================\n";
                    cout << "Item Name: " << foundItem->itemName << endl;
                    cout << "Available Quantity: " << foundItem->availableQuantity << endl;
                    cout << "Per Unit Price: " << foundItem->perUnitPrice << endl;
                }
                else
                {
                    cout << "-> Item not found in inventory." << endl;
                }

                cout << "1. Admin menu" << endl
                     << "2. Main menu" << endl;
                cin >> choice;

                if (choice == '1')
                {
                    goto adminMenu;
                }
                else if (choice == '2')
                {
                    goto loginMenu;
                }
                else
                {
                    cout << "Invalid option, returning to Admin menu..." << endl;
                    goto adminMenu;
                }
            }
            else
            {
                cout << "Invalid option, returning to Admin menu..." << endl;
                goto adminMenu;
            }
        }
        else
        {
            cout << "-> Invalid admin credentials. Returning to main menu..." << endl;
            goto loginMenu;
        }
    }

    else if (choice == '3')
    {
        // Delete item from inventory
        cout << "============================================\n"
             << "                  Delete Item                \n"
             << "============================================\n";
        cout << "Enter Name of The Item: ";
        cin.ignore();
        getline(cin, itemName);
        cout << "Enter Price of the Product: ";
        cin >> price;
        removeItem(root, price);
        cout << "-> Item was Removed Successfully..." << endl;
        inorderTraversal(root);
        cout << "\n1. Admin menu" << endl
             << "2. Main menu" << endl;
        cin >> choice;
        if (choice == '1')
        {
            goto adminMenu;
        }
        else if (choice == '2')
        {
            goto loginMenu;
        }
        else
        {
            cout << "Invalid option...\n";
        }
    }
    else if (choice == '4')
    {
        // Print inventory
        cout << "============================================\n"
             << "                Available Items              \n"
             << "============================================\n";
        inorderTraversal(root);
        cout << "\n1. Admin menu" << endl
             << "2. Main menu" << endl;
        cin >> choice;
        if (choice == '1')
        {
            goto adminMenu;
        }
        else if (choice == '2')
        {
            goto loginMenu;
        }
        else
        {
            cout << "Invalid option...\n";
        }
    }
    else if (choice == '5')
    {
        // Show product with smallest price
        cout << "============================================\n"
             << "              Smallest Price Product         \n"
             << "============================================\n";
        item *smallest = findMin(root);
        if (smallest)
        {
            cout << "Item Name: " << smallest->itemName << endl;
            cout << "Available Quantity: " << smallest->availableQuantity << endl;
            cout << "Per Unit Price: " << smallest->perUnitPrice << endl;
        }
        else
        {
            cout << "-> Inventory is empty.\n";
        }
        cout << "\n1. Admin menu" << endl
             << "2. Main menu" << endl;
        cin >> choice;
        if (choice == '1')
        {
            goto adminMenu;
        }
        else if (choice == '2')
        {
            goto loginMenu;
        }
        else
        {
            cout << "Invalid option...\n";
        }
    }
    else if (choice == '6')
    {
        // Show product with largest price
        cout << "============================================\n"
             << "              Largest Price Product          \n"
             << "============================================\n";
        item *largest = findMax(root);
        if (largest)
        {
            cout << "Item Name: " << largest->itemName << endl;
            cout << "Available Quantity: " << largest->availableQuantity << endl;
            cout << "Per Unit Price: " << largest->perUnitPrice << endl;
        }
        else
        {
            cout << "-> Inventory is empty.\n";
        }
        cout << "\n1. Admin menu" << endl
             << "2. Main menu" << endl;
        cin >> choice;
        if (choice == '1')
        {
            goto adminMenu;
        }
        else if (choice == '2')
        {
            goto loginMenu;
        }
        else
        {
            cout << "Invalid option...\n";
        }
    }
    else if (choice == '7')
    {
        // Print customer details
        cout << "============================================\n"
             << "                Customer Details             \n"
             << "============================================\n";
        printHashTable();
        cout << "Do you want to print customer details in a file (Y/N): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            printHashTableInFile();
            cout << "File has been created successfully...\n";
        }
        cout << "1. Admin menu" << endl
             << "2. Main menu" << endl;
        cin >> choice;
        if (choice == '1')
        {
            goto adminMenu;
        }
        else if (choice == '2')
        {
            goto loginMenu;
        }
        else
        {
            cout << "Invalid option...\n";
        }
    }
    else if (choice == '8')
    {
        // Search customer
        cout << "============================================\n"
             << "               Search Customer               \n"
             << "============================================\n";
        cout << "Enter user name: ";
        cin >> userName;
        cout << "Enter password: ";
        cin >> userPassword;
        searchRecord(userName, userPassword);
        cout << "1. Admin menu" << endl
             << "2. Main menu" << endl;
        cin >> choice;
        if (choice == '1')
        {
            goto adminMenu;
        }
        else if (choice == '2')
        {
            goto loginMenu;
        }
        else
        {
            cout << "Invalid option...\n";
        }
    }
    else if (choice == '9')
    {
        // Print orders
        cout << "============================================\n"
             << "                Placed Orders                \n"
             << "============================================\n";
        printGraph(graph, order1); // Assuming order1 is the example order
        cout << "1. Admin menu" << endl
             << "2. Main menu" << endl;
        cin >> choice;
        if (choice == '1')
        {
            goto adminMenu;
        }
        else if (choice == '2')
        {
            goto loginMenu;
        }
        else
        {
            cout << "Invalid option...\n";
        }
    }
    else if (choice == '0')
    {
        // Route design
        cout << "============================================\n"
             << "                 Route Design                \n"
             << "============================================\n";
        dijkstra(graph, order1); // Assuming order1 is used for demonstration
        cout << "1. Admin menu" << endl
             << "2. Main menu" << endl;
        cin >> choice;
        if (choice == '1')
        {
            goto adminMenu;
        }
        else if (choice == '2')
        {
            goto loginMenu;
        }
        else
        {
            cout << "Invalid option...\n";
        }
    }

    // Handle incorrect admin credentials
    else if (userName == "admin123" && userPassword != "admin123")
    {
        cout << "Incorrect password...\n";
    }
    else if (userName != "admin123" && userPassword == "admin123")
    {
        cout << "Incorrect user name...\n";
    }
    else if (choice == '2')
    {
        // Customer Login
        cout << "============================================\n"
             << "             Login as Customer              \n"
             << "============================================\n";
    customerMenu:
        cout << "1. Track your parcel\n"
             << "2. Create account\n"
             << "3. Display inventory\n"
             << "0. Return to Main Menu\n";
        cin >> choice;
        cin.ignore();

        if (choice == '1')
        {
            // Track parcel
            cout << "============================================\n"
                 << "               Track Parcel                \n"
                 << "============================================\n";
            cout << "Enter username: ";
            getline(cin, userName);
            cout << "Enter password: ";
            getline(cin, userPassword);

            if (searchRecord(userName, userPassword))
            {
                searchOrder(graph, userName, userPassword);
            }
            else
            {
                cout << "Invalid credentials. Please try again.\n";
            }

            cout << "1. Customer menu\n"
                 << "2. Main menu\n";
            cin >> choice;
            if (choice == '1')
            {
                goto customerMenu;
            }
            else if (choice == '2')
            {
                goto loginMenu;
            }
            else
            {
                cout << "Invalid option. Returning to Customer menu...\n";
                goto customerMenu;
            }
        }
        else if (choice == '2')
        {
            // Create account
            cout << "============================================\n"
                 << "             Create a New Account          \n"
                 << "============================================\n";
            cout << "Enter username: ";
            getline(cin, userName);
            cout << "Enter password: ";
            getline(cin, userPassword);

            insertRecord(userName, userPassword);
            cout << "-> Your account was created successfully...\n";

        buyItem:
            cout << "============================================\n"
                 << "               Available Items             \n"
                 << "============================================\n";
            inorderTraversal(root);

            cout << "Enter name of the item to buy: ";
            getline(cin, itemName);
            cout << "Enter price: ";
            cin >> price;
            cin.ignore();

            item *selectedItem = searchItem(root, itemName, price);
            if (selectedItem)
            {
                placeOrder(selectedItem);
                printGraph(graph, order1);
            }
            else
            {
                cout << "Item not found. Please try again.\n";
            }

            cout << "Do you want to place another order? (Y/N): ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                cin.ignore();
                goto buyItem;
            }
            else if (choice == 'n' || choice == 'N')
            {
                goto loginMenu;
            }
            else
            {
                cout << "Invalid option. Returning to Main Menu...\n";
                goto loginMenu;
            }
        }
        else if (choice == '3')
        {
            // Display Inventory
            cout << "============================================\n"
                 << "               Available Items             \n"
                 << "============================================\n";
            inorderTraversal(root);
            cout << "1. Customer menu\n"
                 << "2. Main menu\n";
            cin >> choice;
            if (choice == '1')
            {
                goto customerMenu;
            }
            else if (choice == '2')
            {
                goto loginMenu;
            }
            else
            {
                cout << "Invalid option. Returning to Customer menu...\n";
                goto customerMenu;
            }
        }
        else if (choice == '0')
        {
            goto loginMenu;
        }
        else
        {
            cout << "Invalid option. Please try again.\n";
            goto customerMenu;
        }
    }
}

int main()
{
    parcelDistributionSystem();
    return 0;
}