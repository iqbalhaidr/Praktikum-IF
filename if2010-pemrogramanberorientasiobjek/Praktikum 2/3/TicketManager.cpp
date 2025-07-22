#include "TicketManager.hpp"

#include <iostream>

using namespace std;

TicketManager::TicketManager(string eventName)
    : eventName(eventName),
      vipCapacity(5),
      regularCapacity(10),
      ticketCount(0),
      currentRegularTickets(0),
      currentVIPTickets(0) {
    for (int i = 0; i < VENUE_CAPACITY; i++) {
        tickets[i] = nullptr;
    }
}
/* Constructor default:
 * - Membuat event dengan nama yang diberikan.
 * - Kapasitas default: 5 tiket VIP, 10 tiket Regular.
 * - Tidak ada tiket yang terjual pada awalnya.
 */

TicketManager::TicketManager(string eventName, int vipCapacity,
                             int regularCapacity) {
    if ((vipCapacity + regularCapacity) <= VENUE_CAPACITY) {
        this->vipCapacity = vipCapacity;
        this->regularCapacity = regularCapacity;
        this->eventName = eventName;
        this->ticketCount = 0;
        this->currentRegularTickets = 0;
        this->currentVIPTickets = 0;
        for (int i = 0; i < VENUE_CAPACITY; i++) {
            tickets[i] = nullptr;
        }
    } else {
        cout << "The total capacity you construct is "
             << (vipCapacity + regularCapacity)
             << ", meanwhile the venue capacity is 15" << endl;
    }
}
/* Constructor dengan kapasitas yang ditentukan:
 * - Membuat event dengan kapasitas khusus untuk VIP dan Regular.
 * - Jika total kapasitas melebihi VENUE_CAPACITY, cetak:
 *   "The total capacity you construct is <total>, meanwhile the venue capacity
 * is 15"
 */

TicketManager::~TicketManager() {
    int totalSold = currentRegularTickets + currentVIPTickets;
    for (int i = 0; i < totalSold; i++) {
        delete tickets[i];
        tickets[i] = nullptr;
    }
}
/* Destructor:
 * - Membersihkan semua tiket yang telah dialokasikan secara dinamis.
 * - Menetapkan pointer tiket menjadi nullptr setelah dihapus.
 */

string TicketManager::getEventName() const { return eventName; }
/* Mengembalikan nama acara yang dikelola oleh TicketManager.
 * Output: Nama acara dalam bentuk string.
 */

void TicketManager::buyTicket(const string &ownerName, bool isVIP) {
    if (ticketCount >= VENUE_CAPACITY) {
        cout << "Error: All tickets are sold out!" << endl;
        return;
    }

    if (isVIP) {
        if (currentVIPTickets >= vipCapacity) {
            cout << "Error: No VIP tickets left!" << endl;
        } else {
            // jangan lupa tambah2 state
            int angka = currentVIPTickets + 1;
            string hasil = "V" + to_string(angka);
            tickets[ticketCount] = new VIPTicket(hasil, ownerName);
            ticketCount++;
            currentVIPTickets++;
            cout << "Success: " << ownerName
                 << " bought a VIP ticket! Ticket ID: " << hasil << endl;
        }
    } else {
        if (currentRegularTickets >= regularCapacity) {
            cout << "Error: No Regular tickets left!" << endl;
        } else {
            int angka = currentRegularTickets + 1;
            string hasil = "R" + to_string(angka);
            tickets[ticketCount] = new RegularTicket(hasil, ownerName);
            ticketCount++;
            currentRegularTickets++;
            cout << "Success: " << ownerName
                 << " bought a Regular ticket! Ticket ID: " << hasil << endl;
        }
    }
}
/* Membeli tiket untuk pengguna.
 * Input:
 * - ownerName: Nama pemilik tiket.
 * - isVIP: Jika true, membeli tiket VIP; jika false, membeli tiket Regular.
 *
 * Proses:
 * - Jika venue penuh, cetak "Error: All tickets are sold out!".
 * - Jika kapasitas VIP penuh, cetak "Error: No VIP tickets left!".
 * - Jika kapasitas Regular penuh, cetak "Error: No Regular tickets left!".
 *
 * - Jika pembelian berhasil, sistem akan membuat **ID tiket unik** berdasarkan
 * jenis tiket:
 *   - Jika tiket VIP, ID akan berupa "V" diikuti nomor urut tiket VIP.
 *   - Jika tiket Regular, ID akan berupa "R" diikuti nomor urut tiket Regular.
 *
 * - Contoh penggunaan `to_string()` dalam pembuatan ID:
 *   int angka = 5;
 *   string hasil = "V" + to_string(angka); // hasil: "V5"
 *
 * - Jika pembelian berhasil, cetak:
 *   "Success: <ownerName> bought a <VIP/Regular> ticket! Ticket ID: <ticketID>"
 */

void TicketManager::checkTicket(const string &ticketID) const {
    bool isFound = false;
    int idx = -1;

    for (int i = 0; i < ticketCount; i++) {
        if (tickets[i]->getTicketID() == ticketID) {
            isFound = true;
            idx = i;
        }
    }

    if (isFound) {
        tickets[idx]->printTicket();
    } else {
        cout << "Ticket ID is invalid!" << endl;
    }
}
/* Mengecek apakah tiket dengan ID tertentu valid.
 * Input:
 * - ticketID: ID tiket yang ingin diperiksa.
 *
 * Output:
 * - Jika ditemukan, cetak detail tiket menggunakan metode printTicket().
 * - Jika tidak ditemukan, cetak "Ticket ID is invalid!".
 */

void TicketManager::listAudience() const {
    if (ticketCount <= 0) {
        cout << "No audience yet!" << endl;
    } else {
        for (int i = 0; i < ticketCount; i++) {
            cout << i + 1 << ". ";
            tickets[i]->printTicket();
        }
    }
}
/* Menampilkan daftar semua pemegang tiket.
 * Output:
 * - Jika belum ada yang membeli tiket, cetak "No audience yet!".
 * - Jika ada, cetak dalam format:
 *   "<nomor>. <printTicket()>"
 *
 * - Nomor urut dalam output harus dimulai dari 1.
 */

int TicketManager::calculateRevenue() const {
    int revenue = (currentVIPTickets * 500) + (currentRegularTickets * 275);
    return revenue;
}
/* Menghitung total pendapatan dari tiket yang terjual.
 * - Tiket VIP seharga 500.
 * - Tiket Regular seharga 275.
 *
 * Output: Total pendapatan dalam bentuk integer.
 */