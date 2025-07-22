#include "SpacingGuildShip.hpp"

#include <iostream>

using namespace std;

float SpacingGuildShip::totalGuildTravel = 0;
int SpacingGuildShip::producedShips = 0;

SpacingGuildShip::SpacingGuildShip()
    : maxPassengerCap(50),
      guildNavigatorCount(3),
      serialNum(producedShips + 1) {
    this->passengerCount = 0;
    this->operatingGuildNavigator = 3;
    this->spiceStock = 50;
    producedShips++;
}

SpacingGuildShip::SpacingGuildShip(int maxPassengerCap, int guildNavigatorCount,
                                   int spiceStock)
    : maxPassengerCap(maxPassengerCap),
      guildNavigatorCount(guildNavigatorCount),
      serialNum(producedShips + 1) {
    this->passengerCount = 0;
    this->operatingGuildNavigator = guildNavigatorCount;
    this->spiceStock = spiceStock;
    producedShips++;
}

SpacingGuildShip::SpacingGuildShip(const SpacingGuildShip& s)
    : maxPassengerCap(s.maxPassengerCap),
      guildNavigatorCount(s.guildNavigatorCount),
      serialNum(producedShips + 1) {
    this->passengerCount = s.passengerCount;
    this->operatingGuildNavigator = s.operatingGuildNavigator;
    this->spiceStock = s.spiceStock;
    producedShips++;
}

SpacingGuildShip::~SpacingGuildShip() {}

int SpacingGuildShip::getShipSerialNum() const { return this->serialNum; }

int SpacingGuildShip::getPassengerCount() const { return this->passengerCount; }

void SpacingGuildShip::travel(float distance) {
    if (this->operatingGuildNavigator > 0) {
        totalGuildTravel += distance / (E * E * this->operatingGuildNavigator);
        this->operatingGuildNavigator--;
    }
}
/* Pesawat bergerak sebesar distance, sehingga
 * totalGuildTravel bertambah sebesar:
 *
 * distance / (E^2 * operatingGuildNavigator).
 *
 * Catatan:
 * 1. Apabila tidak ada Guild Navigator yang operasional,
 *    maka totalGuildTravel tidak bertambah;
 * 2. Apabila ada Guild Navigator yang operasional,
 *    maka jumlah Guild Navigator operasional berkurang 1 */

void SpacingGuildShip::boarding(int addedPassengers) {
    if ((addedPassengers + passengerCount) > maxPassengerCap) {
        passengerCount = maxPassengerCap;
    } else {
        passengerCount += addedPassengers;
    }
}
/* Penumpang naik ke pesawat sebesar addedPassenger.
 * Jika pesawat tidak muat, penumpang pesawat menjadi penuh */

void SpacingGuildShip::dropOff(int droppedPassengers) {
    if (droppedPassengers > passengerCount) {
        passengerCount = 0;
    } else {
        passengerCount -= droppedPassengers;
    }
}
/* Penumpang turun dari pesawat sebesar droppedPassenger.
 * Jika jumlah penumpang kurang, kosongkan pesawat */

void SpacingGuildShip::refreshNavigator(int n) {}
// Gapaham maksudnya apa

/* Menambah n Guild Navigator operasional yang menghabiskan
 * n * GUILD_NAVIGATOR_SPICE_DOSE spice dari stok.
 *
 * Catatan:
 * 1. Maksimum merefresh seluruh Guild Navigator yang ada di pesawat
 * 2. Apabila stok kurang, maka merefresh n maksimum yang dapat di refresh
 *    dari stok spice yang ada */

void SpacingGuildShip::transitToArrakis(int addedSpice) {
    this->spiceStock += addedSpice;
}
/* Menambah stok spice sebesar addedSpice */