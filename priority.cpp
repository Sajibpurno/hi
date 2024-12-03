#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int bt[n], wt[n], pr[n], pos, temp;
    float awt = 0;

    cout << "Enter burst time and priority for each process:" << endl;
    for (int a = 0; a < n; a++) {
        cout << "Process " << a + 1 << " burst time: ";
        cin >> bt[a];
        cout << "Process " << a + 1 << " priority: ";
        cin >> pr[a];
    }

    // Sorting based on priority
    for (int i = 0; i < n; i++) {
        pos = i;
        for (int j = i + 1; j < n; j++) {
            if (pr[j] < pr[pos]) {
                pos = j;
            }
        }

        // Swapping priorities
        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;

        // Swapping burst times
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
    }

    wt[0] = 0; // Waiting time for first process is 0

    // Calculating waiting times
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        awt += wt[i];
    }

    awt /= n; // Average waiting time

    cout << fixed << setprecision(2);
    cout << "Average Waiting Time: " << awt << endl;

    return 0;
}

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int bt[n], wt[n], pr[n], pos, temp;
    float awt = 0;

    cout << "Enter burst time and priority for each process:" << endl;
    for (int a = 0; a < n; a++) {
        cout << "Process " << a + 1 << " burst time: ";
        cin >> bt[a];
        cout << "Process " << a + 1 << " priority: ";
        cin >> pr[a];
    }

    // Sorting based on priority
    for (int i = 0; i < n; i++) {
        pos = i;
        for (int j = i + 1; j < n; j++) {
            if (pr[j] < pr[pos]) {
                pos = j;
            }
        }

        // Swapping priorities
        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;

        // Swapping burst times
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
    }

    wt[0] = 0; // Waiting time for first process is 0

    // Calculating waiting times
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        awt += wt[i];
    }

    awt /= n; // Average waiting time

    cout << fixed << setprecision(2);
    cout << "Average Waiting Time: " << awt << endl;

    return 0;
}


//c code- #include <stdio.h>

// int main() 
// {
//     int n;
//     printf("Enter number of processes: ");
//     scanf("%d", &n);
//     int bt[n], wt[n], pos, temp, pr[n];
//     float awt = 0;

//     printf("Enter burst time and priority for each process:\n");
//     for (int a = 0; a < n; a++) {
//         printf("Process %d burst time: ", a + 1);
//         scanf("%d", &bt[a]);
//         printf("Process %d priority: ", a + 1);
//         scanf("%d", &pr[a]);
//     }

    
//     for (int i = 0; i < n; i++) {
//         pos = i;
//         for (int j = i + 1; j < n; j++) {
//             if (pr[j] < pr[pos]) {
//                 pos = j;
//             }
//         }
        
        
//         temp = pr[i];
//         pr[i] = pr[pos];
//         pr[pos] = temp;
        
       
//         temp = bt[i];
//         bt[i] = bt[pos];
//         bt[pos] = temp;
//     }

//     wt[0] = 0;
    
    
//     for (int i = 1; i < n; i++) {
//         wt[i] = wt[i - 1] + bt[i - 1];
//         awt += wt[i];
//     }

//     awt /= n; 

//     printf("Average Waiting Time: %.2f\n", awt);

//     return 0;
// }
