public interface EnergyMonitored {
    double getEnergyConsumption();

    // Skala 1-5, 5 artinya sangat efisien
    int getEnergyEfficiencyRating();
}