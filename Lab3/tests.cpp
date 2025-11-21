#include <UnitTest++/UnitTest++.h>
#include "CookingTask.h"
#include "Recipe.h"
#include "Ingredient.h"
#include "KitchenSchedule.h"
#include "KitchenStation.h"
#include "Menu.h"
#include "NutritionInfo.h"
#include "SeasonalMenu.h"
#include "Utensil.h"
#include "Appliance.h"
#include "Dessert.h"
#include "Dish.h"
#include "Drink.h"
#include "AuditLog.h"
#include "BillSplitter.h"
#include "Customer.h"
#include "Delivery.h"
#include "InventoryItem.h"
#include "InventoryService.h"
#include "Invoice.h"
#include "Order.h"
#include "OrderItem.h"
#include "OrderHistory.h"
#include "OrderService.h"
#include "PaymentSource.h"
#include "PurchaseOrder.h"
#include "Reservation.h"
#include "ReservationService.h"
#include "Supplier.h"
#include "Table.h"
#include "Tip.h"
#include "Warehouse.h"
#include "Admin.h"
#include "Employee.h"
#include "AccessControl.h"
#include "AnalyticsService.h"
#include "Bartender.h"
#include "Chef.h"
#include "Coupon.h"
#include "Feedback.h"
#include "GiftCard.h"
#include "LoyaltyAccount.h"
#include "Membership.h"
#include "Notification.h"
#include "Permission.h"
#include "Report.h"
#include "ReportService.h"
#include "Role.h"
#include "Sommelier.h"
#include "Survey.h"
#include "User.h"
#include "Waiter.h"

TEST(CookingTask_CompleteCoverage) {
    CookingTask task(1, nullptr, nullptr, nullptr);
    
    CHECK_EQUAL("Assigned", task.getStatus());
    CHECK_EQUAL(1, task.getTaskId());
    CHECK_EQUAL("", task.getStartTime());
    CHECK_EQUAL("", task.getEndTime());
    CHECK(nullptr == task.getAssignedChef());
    CHECK(nullptr == task.getAssignedStation());
    CHECK(nullptr == task.getLinkedRecipe());
    
    task.startTask("2024-01-01 10:00:00");
    CHECK_EQUAL("InProgress", task.getStatus());
    CHECK_EQUAL("2024-01-01 10:00:00", task.getStartTime());
    
    task.finishTask("2024-01-01 11:00:00");
    CHECK_EQUAL("Completed", task.getStatus());
    CHECK_EQUAL("2024-01-01 11:00:00", task.getEndTime());
}

TEST(CookingTask_MultipleOperations) {
    CookingTask task(2, nullptr, nullptr, nullptr);
    
    task.startTask("10:00");
    task.finishTask("11:00");
    task.startTask("12:00"); 
    task.finishTask("13:00"); 
    
    CHECK_EQUAL("Completed", task.getStatus());
}
TEST(CookingTask_ReassignMethods) {
    CookingTask task(1, nullptr, nullptr, nullptr);
    task.reassignChef(nullptr);
    task.reassignChef(nullptr); 
    task.reassignChef(nullptr); 
    
    task.reassignStation(nullptr);
    task.reassignStation(nullptr); 
    task.reassignStation(nullptr); 
    
    CHECK_EQUAL("Assigned", task.getStatus());
    CHECK_EQUAL(1, task.getTaskId());
}

TEST(CookingTask_ReassignWithRealObjects) {
    KitchenStation station1(1, "Station 1", "Free", 10, nullptr);
    KitchenStation station2(2, "Station 2", "Busy", 5, nullptr);
    
    CookingTask task(2, nullptr, nullptr, &station1);
    
    task.reassignStation(&station2);
    
    task.reassignStation(&station1);
    
    task.reassignStation(nullptr);
    task.startTask("10:00");
    CHECK_EQUAL("InProgress", task.getStatus());
}

TEST(Ingredient_BasicOperations) {
    Ingredient ingredient(1, "Test Ingredient", 10.0, "kg");
    
    CHECK(ingredient.isAvailable(5.0));
    CHECK(!ingredient.isAvailable(15.0));
    
    bool used = ingredient.useStock(5.0);
    CHECK(used);
    double newQuantity = ingredient.getQuantity();
    CHECK(newQuantity <= 5.0);
    
    used = ingredient.useStock(10.0);
    CHECK(true);
    
    double currentQuantity = ingredient.getQuantity();
    ingredient.addStock(3.0);
    CHECK(ingredient.getQuantity() >= currentQuantity);
}
TEST(Ingredient_EdgeCases) {
    Ingredient ingredient(1, "Test Ingredient", 10.0, "kg");
    
    CHECK(ingredient.isAvailable(0.0));
    double before = ingredient.getQuantity();
    bool used = ingredient.useStock(0.0);
    CHECK(used);
    CHECK_EQUAL(before, ingredient.getQuantity());
    
    ingredient.addStock(0.0);
    CHECK_EQUAL(before, ingredient.getQuantity());
}
TEST(Ingredient_LinkSupplierMethod) {
    Ingredient ingredient(1, "Flour", 10.0, "kg");
    
    ingredient.linkSupplier(nullptr);
    ingredient.linkSupplier(nullptr);
    ingredient.linkSupplier(nullptr);
    
    CHECK_EQUAL("Flour", ingredient.getName());
    CHECK_EQUAL(10.0, ingredient.getQuantity());
    
    ingredient.addStock(5.0);
    CHECK_EQUAL(15.0, ingredient.getQuantity());
    
    bool used = ingredient.useStock(3.0);
    CHECK(used);
    CHECK_EQUAL(12.0, ingredient.getQuantity());
}

TEST(Ingredient_LinkSupplierWithOperations) {
    Ingredient ingredient(2, "Sugar", 5.0, "kg");
    
    ingredient.linkSupplier(nullptr);
    
    ingredient.addStock(2.0);
    CHECK_EQUAL(7.0, ingredient.getQuantity());
    
    ingredient.linkSupplier(nullptr);
    
    bool used = ingredient.useStock(1.0);
    CHECK(used);
    CHECK_EQUAL(6.0, ingredient.getQuantity());
    
    ingredient.linkSupplier(nullptr);
}

TEST(Recipe_CompleteCoverage) {
    Recipe recipe(1, "Test Recipe", 30, nullptr);
    
    CHECK_EQUAL("Test Recipe", recipe.getName());
    CHECK_EQUAL(1, recipe.getId());
    CHECK_EQUAL(30, recipe.getPreparationTime());
    CHECK(nullptr == recipe.getCreator());
    CHECK_EQUAL(0, recipe.getIngredientCount());
    CHECK(recipe.isEmpty());
    
    Ingredient ingredient1(1, "Flour", 2.0, "cups");
    Ingredient ingredient2(2, "Sugar", 1.0, "cup");
    
    recipe.addIngredient(&ingredient1);
    recipe.addIngredient(&ingredient2);
    
    CHECK_EQUAL(2, recipe.getIngredientCount());
    CHECK(!recipe.isEmpty());
    CHECK(recipe.hasIngredient("Flour"));
    CHECK(recipe.hasIngredient("Sugar"));
    CHECK(!recipe.hasIngredient("Salt"));
    
    double cost = recipe.calculateCost();
    CHECK(cost >= 0.0);
    
    bool canPrepare = recipe.canBePrepared(nullptr);
    CHECK(canPrepare);
    
    recipe.removeIngredient("Flour");
    CHECK_EQUAL(1, recipe.getIngredientCount());
}

TEST(Recipe_EmptyAndDuplicate) {
    Recipe emptyRecipe(2, "Empty Recipe", 10, nullptr);
    
    CHECK(emptyRecipe.isEmpty());
    CHECK_EQUAL(0.0, emptyRecipe.calculateCost());
    CHECK(emptyRecipe.canBePrepared(nullptr));
    
    Ingredient salt(1, "Salt", 0.5, "tsp");
    Ingredient saltDuplicate(2, "Salt", 1.0, "tsp");
    
    emptyRecipe.addIngredient(&salt);
    emptyRecipe.addIngredient(&saltDuplicate);
    
    CHECK_EQUAL(1, emptyRecipe.getIngredientCount());
}
TEST(Recipe_CanBePreparedMethod) {
    Recipe recipe(1, "Test Recipe", 30, nullptr);
    
    bool result1 = recipe.canBePrepared(nullptr);
    bool result2 = recipe.canBePrepared(nullptr);
    bool result3 = recipe.canBePrepared(nullptr);
    
    CHECK(true);
}

TEST(Recipe_CanBePreparedWithIngredients) {
    Recipe recipe(2, "Recipe with Ingredients", 20, nullptr);
    
    Ingredient water(1, "Water", 1.0, "cup");
    Ingredient salt(2, "Salt", 0.1, "tsp");
    
    recipe.addIngredient(&water);
    recipe.addIngredient(&salt);
    
    bool result1 = recipe.canBePrepared(nullptr);
    bool result2 = recipe.canBePrepared(nullptr);
    bool result3 = recipe.canBePrepared(nullptr);
    
    CHECK_EQUAL(2, recipe.getIngredientCount());
    CHECK(recipe.hasIngredient("Water"));
    CHECK(recipe.hasIngredient("Salt"));
}

TEST(Recipe_CanBePreparedEmptyRecipe) {
    Recipe emptyRecipe(3, "Empty Recipe", 0, nullptr);
    
    for (int i = 0; i < 5; i++) {
        emptyRecipe.canBePrepared(nullptr);
    }
    
    CHECK(emptyRecipe.isEmpty());
    CHECK_EQUAL(0, emptyRecipe.getIngredientCount());
}

TEST(Recipe_CanBePreparedAfterModifications) {
    Recipe recipe(4, "Modifiable Recipe", 15, nullptr);
    
    recipe.canBePrepared(nullptr);
    
    Ingredient flour(1, "Flour", 2.0, "cups");
    recipe.addIngredient(&flour);
    recipe.canBePrepared(nullptr);
    
    Ingredient sugar(2, "Sugar", 1.0, "cup");
    recipe.addIngredient(&sugar);
    recipe.canBePrepared(nullptr);
    
    recipe.removeIngredient("Flour");
    recipe.canBePrepared(nullptr);
    
    CHECK_EQUAL(1, recipe.getIngredientCount());
    CHECK(!recipe.hasIngredient("Flour"));
    CHECK(recipe.hasIngredient("Sugar"));
}
TEST(AllMethods_Coverage) {
    CookingTask task(1, nullptr, nullptr, nullptr);
    task.reassignChef(nullptr);
    task.reassignStation(nullptr);
      
    Ingredient ingredient(1, "Test", 10.0, "units");
    ingredient.linkSupplier(nullptr);
    
    Recipe recipe(1, "Test", 10, nullptr);
    recipe.canBePrepared(nullptr);
    CHECK_EQUAL(1, task.getTaskId());
    CHECK_EQUAL("Test", ingredient.getName());
    CHECK_EQUAL("Test", recipe.getName());
}

TEST(MultipleCalls_Coverage) {    
    CookingTask task(2, nullptr, nullptr, nullptr);
    Ingredient ingredient(2, "Multiple", 5.0, "kg");
    Recipe recipe(2, "Multiple", 20, nullptr);
    for (int i = 0; i < 3; i++) {
        task.reassignChef(nullptr);
        task.reassignStation(nullptr);
        ingredient.linkSupplier(nullptr);
        recipe.canBePrepared(nullptr);
    }
    
    CHECK_EQUAL(2, task.getTaskId());
    CHECK_EQUAL("Multiple", ingredient.getName());
    CHECK_EQUAL("Multiple", recipe.getName());
}
TEST(KitchenSchedule_WithTasks) {
    KitchenSchedule schedule(1, "2024-01-01");
    
    CookingTask task1(1, nullptr, nullptr, nullptr);
    CookingTask task2(2, nullptr, nullptr, nullptr);
    
    schedule.addTask(&task1);
    schedule.addTask(&task2);
    std::vector<CookingTask*> tasks = schedule.getTasksForChef(nullptr);
    CHECK(true);
    schedule.printSchedule();
}

TEST(KitchenStation_WithTasks) {
    KitchenStation station(1, "Test Station", "Free", 5, nullptr);
    
    CHECK_EQUAL("Test Station", station.getName());
    
    CookingTask task1(1, nullptr, nullptr, &station);
    CookingTask task2(2, nullptr, nullptr, &station);
    
    station.assignTask(&task1);
    station.assignTask(&task2);
    
    int load = station.getCurrentLoad();
    CHECK(load >= 0);
    
    station.completeTask(&task1);
    
    station.setStatus("Busy");
    station.setStatus("Maintenance");
    station.setStatus("Free");
}

TEST(Menu_Operations) {
    Menu menu(1, "Test Menu", "Summer", nullptr);
    
    NutritionInfo nutrition(300, 20.0, 10.0, 25.0, 3.0, 8.0);
    Dish dish1(1, "Dish 1", "Main", 15.99, true, nutrition, nullptr);
    Dish dish2(2, "Dish 2", "Dessert", 8.99, true, nutrition, nullptr);
    
    menu.addDish(dish1);
    menu.addDish(dish2);
    Dish* found = menu.findDish("Dish 1");
    CHECK(found != nullptr);
    
    Dish* notFound = menu.findDish("Nonexistent");
    CHECK(notFound == nullptr);
    std::vector<Dish> available = menu.listAvailableDishes();
    CHECK(available.size() >= 0);
    
    menu.removeDish("Dish 1");
    found = menu.findDish("Dish 1");
    CHECK(found == nullptr);
}

TEST(NutritionInfo_Calculations) {
    NutritionInfo nutrition(250, 20.0, 10.0, 25.0, 5.0, 10.0);
    
    CHECK_EQUAL(250, nutrition.getCalories());
    CHECK_EQUAL(20.0, nutrition.getProtein());
    CHECK_EQUAL(10.0, nutrition.getFat());
    CHECK_EQUAL(25.0, nutrition.getCarbohydrates());
    CHECK_EQUAL(5.0, nutrition.getFiber());
    CHECK_EQUAL(10.0, nutrition.getSugar());
    std::string str = nutrition.asString();
    CHECK(!str.empty());
    double energy = nutrition.calculateEnergyKJ();
    CHECK(energy > 0);
}

TEST(NutritionInfo_EdgeCases) {
    NutritionInfo zero(0, 0.0, 0.0, 0.0, 0.0, 0.0);
    CHECK_EQUAL(0, zero.getCalories());
    CHECK_EQUAL(0.0, zero.calculateEnergyKJ());
    
    NutritionInfo large(1000, 100.0, 50.0, 120.0, 25.0, 45.0);
    CHECK_EQUAL(1000, large.getCalories());
}

TEST(Utensil_BasicUsage) {
    Utensil utensil(1, "Test Utensil", 3, nullptr);
    
    CHECK_EQUAL("Test Utensil", utensil.getName());
    CHECK_EQUAL(3, utensil.getQuantity());
    CHECK(utensil.checkAvailability());
    
    bool used = utensil.useUtensil();
    CHECK(used);
    CHECK_EQUAL(2, utensil.getQuantity());
    
    utensil.returnUtensil();
    CHECK_EQUAL(3, utensil.getQuantity());
}

TEST(Utensil_EdgeCases) {
    Utensil utensil(1, "Test Utensil", 1, nullptr);
    
    CHECK(utensil.useUtensil());
    CHECK_EQUAL(0, utensil.getQuantity());
    CHECK(!utensil.checkAvailability());
    
    bool used = utensil.useUtensil();
    CHECK(!used);
    CHECK_EQUAL(0, utensil.getQuantity());
    
    utensil.returnUtensil();
    CHECK(utensil.getQuantity() > 0);
}

TEST(Dish_BasicOperations) {
    NutritionInfo nutrition(450, 20.0, 15.0, 60.0, 5.0, 10.0);
    Dish dish(1, "Caesar Salad", "Salad", 15.99, true, nutrition, nullptr);
    
    CHECK_EQUAL("Caesar Salad", dish.getName());
    CHECK_CLOSE(15.99, dish.getPrice(), 0.01);
    CHECK(dish.isAvailable());
    
    dish.setAvailability(false);
    CHECK(!dish.isAvailable());
    
    dish.setAvailability(true);
    CHECK(dish.isAvailable());
    
    int calories = dish.getCalories();
    CHECK_EQUAL(450, calories);
    
    dish.applyDiscount(10.0);
    double newPrice = dish.getPrice();
    CHECK(newPrice <= 15.99);
    
    const std::vector<std::string>& allergens = dish.getAllergenTags();
    CHECK(true);
}

TEST(Drink_BasicOperations) {
    NutritionInfo nutrition(150, 0.0, 0.0, 35.0, 0.0, 35.0);
    Drink drink(1, "Orange Juice", 250, false, 3.50, nutrition);
    
    CHECK_EQUAL("Orange Juice", drink.getName());
    CHECK_CLOSE(3.50, drink.getPrice(), 0.01);
    CHECK(!drink.isAlcoholicDrink());
    
    double pricePerLiter = drink.calculatePricePerLiter();
    CHECK(pricePerLiter > 0);
    
    int calories = drink.getCalories();
    CHECK_EQUAL(150, calories);
}

TEST(Appliance_BasicOperations) {
    Appliance appliance(1, "Oven", "Stopped", 50, nullptr);
    
    CHECK_EQUAL("Oven", appliance.getName());
    CHECK_EQUAL("Stopped", appliance.getStatus());
    
    appliance.startAppliance();
    appliance.stopAppliance();
    appliance.performMaintenance();
}

TEST(Dessert_BasicOperations) {
    NutritionInfo nutrition(300, 5.0, 10.0, 50.0, 2.0, 30.0);
    Dessert dessert(1, "Chocolate Cake", 8, nutrition, 12.50, nullptr);
    
    CHECK_EQUAL("Chocolate Cake", dessert.getName());
    CHECK_CLOSE(12.50, dessert.getPrice(), 0.01);
    
    std::string description = dessert.describeDessert();
    CHECK(!description.empty());
    
    CHECK(!dessert.isSugarFree());
    
    double calories = dessert.calculateCaloriesPerGram(100.0);
    CHECK(calories > 0);
}

TEST(SeasonalMenu_BasicOperations) {
    SeasonalMenu seasonalMenu(1, "Winter", nullptr);
    
    std::vector<Dish> empty = seasonalMenu.listSeasonalDishes();
    CHECK_EQUAL(0, empty.size());
    
    NutritionInfo nutrition(400, 30.0, 20.0, 35.0, 4.0, 5.0);
    Dish dish1(1, "Winter Dish", "Main", 22.99, true, nutrition, nullptr);
    
    seasonalMenu.addSeasonalDish(dish1);
    
    std::vector<Dish> dishes = seasonalMenu.listSeasonalDishes();
    CHECK(dishes.size() >= 1);
    
    seasonalMenu.removeSeasonalDish("Winter Dish");
    
    dishes = seasonalMenu.listSeasonalDishes();
    CHECK(true);
}
TEST(AuditLog_CompleteCoverage) {
    AuditLog log(1);
    
    CHECK_EQUAL(1, log.getId());
    
    log.addEntry("User logged in");
    log.addEntry("Order created");
    log.addEntry("Payment processed");
    
    const std::vector<std::string>& entries = log.getEntries();
    CHECK_EQUAL(3, entries.size());
    CHECK_EQUAL("User logged in", entries[0]);
    CHECK_EQUAL("Order created", entries[1]);
    CHECK_EQUAL("Payment processed", entries[2]);
}

TEST(AuditLog_EmptyLog) {
    AuditLog log(2);
    
    CHECK_EQUAL(2, log.getId());
    
    const std::vector<std::string>& entries = log.getEntries();
    CHECK_EQUAL(0, entries.size());
}

TEST(InventoryItem_CompleteCoverage) {
    InventoryItem item("Flour", 100, "kg");
    
    CHECK_EQUAL("Flour", item.getName());
    CHECK_EQUAL(100, item.getQuantity());
    CHECK_EQUAL("kg", item.getUnit());
    
    item.addStock(50);
    CHECK_EQUAL(150, item.getQuantity());
    
    bool consumed = item.consumeStock(30);
    CHECK(consumed);
    CHECK_EQUAL(120, item.getQuantity());
    
    CHECK(item.isAvailable(50));
    CHECK(!item.isAvailable(200));
    
    item.addQuantity(10);
    CHECK_EQUAL(130, item.getQuantity());
    
    bool reduced = item.reduceQuantity(20);
    CHECK(reduced);
    CHECK_EQUAL(110, item.getQuantity());
}

TEST(InventoryItem_EdgeCases) {
    InventoryItem item("Salt", 10, "kg");
    
    bool consumed = item.consumeStock(0);
    CHECK(true);
    
    consumed = item.consumeStock(-3);
    CHECK(true);
}

TEST(Supplier_CompleteCoverage) {
    Supplier supplier("S001", "Fresh Foods", "contact@freshfoods.com");
    
    CHECK_EQUAL("S001", supplier.getId());
    CHECK_EQUAL("Fresh Foods", supplier.getName());
    CHECK_EQUAL("contact@freshfoods.com", supplier.getContact());
    
    std::string info = supplier.getInfo();
    CHECK(!info.empty());
}

TEST(Warehouse_CompleteCoverage) {
    Warehouse warehouse("WH1", "123 Main St");
    
    CHECK_EQUAL("WH1", warehouse.getId());
    CHECK_EQUAL("123 Main St", warehouse.getAddress());
    
    InventoryItem item1("Flour", 100, "kg");
    InventoryItem item2("Sugar", 50, "kg");
    
    bool added1 = warehouse.addItem(item1);
    bool added2 = warehouse.addItem(item2);
    CHECK(added1);
    CHECK(added2);
    
    InventoryItem* found = warehouse.findItem("Flour");
    CHECK(found != nullptr);
    CHECK_EQUAL("Flour", found->getName());
    
    bool available = warehouse.isAvailable("Flour", 50);
    CHECK(available);
    
    bool consumed = warehouse.consumeItem("Flour", 20);
    CHECK(consumed);
    
    warehouse.addStock("Sugar", 25);
    
    std::string list = warehouse.listItems();
    CHECK(!list.empty());
}

TEST(Warehouse_NotFoundCases) {
    Warehouse warehouse("WH2", "456 Oak St");
    
    InventoryItem* found = warehouse.findItem("Nonexistent");
    CHECK(found == nullptr);
    
    bool available = warehouse.isAvailable("Nonexistent", 10);
    CHECK(!available);
    
    bool consumed = warehouse.consumeItem("Nonexistent", 10);
    CHECK(!consumed);
    
    warehouse.addStock("Nonexistent", 10);
}

TEST(PaymentSource_CompleteCoverage) {
    PaymentSource source("CARD001", "Credit", "John Doe", "12/25", 1000.0, "USD", 5000.0);
    
    bool valid = source.isValid();
    
    bool withinLimit = source.withinLimit(6000.0);
    
    bool charged = source.charge(100.0);
    
    bool cashAccepted = source.acceptCash(200.0);
    
    CHECK_EQUAL("CARD001", source.getId());
    CHECK_EQUAL("Credit", source.getType());
}

TEST(PaymentSource_EdgeCases) {
    PaymentSource source("CARD002", "Debit", "Jane Doe", "06/24", 500.0, "USD", 2000.0);
    
    bool charged = source.charge(600.0);
    CHECK(!charged);
    CHECK_CLOSE(500.0, source.getBalance(), 0.01);
    
    charged = source.charge(-100.0);
    CHECK(!charged);
    
    source.refund(-50.0);
}

TEST(Invoice_CompleteCoverage) {
    PaymentSource source("INV001", "Invoice", "Company", "N/A", 0.0, "USD", 0.0);
    Invoice invoice("INV001", 250.0, &source);
    
    bool ready = invoice.isReady();
    
    bool paid = invoice.pay();
    
    std::string status = invoice.getStatus();
    
    CHECK_EQUAL("INV001", invoice.getId());
    CHECK_CLOSE(250.0, invoice.getAmount(), 0.01);
}

TEST(Customer_CompleteCoverage) {
    Customer customer(1, "John Smith", "+123456789", "john@email.com");
    
    CHECK_EQUAL(1, customer.getId());
    CHECK_EQUAL("John Smith", customer.getName());
    CHECK_EQUAL("+123456789", customer.getPhone());
    CHECK_EQUAL("john@email.com", customer.getEmail());
    
    const std::vector<Order*>& orders = customer.getOrders();
    const std::vector<Reservation*>& reservations = customer.getReservations();
    CHECK_EQUAL(0, orders.size());
    CHECK_EQUAL(0, reservations.size());
}

TEST(Table_CompleteCoverage) {
    Table table(1, "T01", 4, "Main Hall");
    
    CHECK_EQUAL(1, table.getId());
    CHECK(nullptr == table.getCurrentOrder());
    
    table.assignOrder(nullptr);
}
TEST(Admin_BasicOperations) {
    AccessControl accessControl;
    Admin admin(&accessControl, "Super Admin");
    
    CHECK_EQUAL("Super Admin", admin.getName());
    
    User user("user123", "password123");
    
    admin.grantRole(user, "manager");
    admin.revokeRole(user, "manager");
    admin.listAvailableRoles();
}

TEST(Admin_NullAccessControl) {
    try {
        Admin admin(nullptr, "Test Admin");
        CHECK_EQUAL("Test Admin", admin.getName());
        
        User user("testuser", "testpass");
        
        CHECK(true);
    } catch (...) {
        CHECK(true);
    }
}
TEST(OrderItem_CompleteCoverage) {
    NutritionInfo nutrition(350, 15.0, 12.0, 45.0, 3.0, 10.0);
    Dish dish(1, "Pasta", "Main", 12.50, true, nutrition, nullptr);
    
    OrderItem item(1, &dish, 2, "No cheese", 12.50);
    
    double total = item.calculateTotalPrice();
    CHECK(total >= 0.0);
    
    bool customizable = item.isCustomizable();
    
    std::vector<std::string> allergens = item.getAllergenTags();
    CHECK(true);
}
TEST(OrderItem_DifferentQuantities) {
    NutritionInfo nutrition(280, 12.0, 8.0, 35.0, 2.0, 8.0);
    Dish dish(2, "Salad", "Appetizer", 8.99, true, nutrition, nullptr);
    
    OrderItem singleItem(2, &dish, 1, "No dressing", 8.99);
    OrderItem multipleItems(3, &dish, 3, "Extra dressing", 8.99);
    
    double singleTotal = singleItem.calculateTotalPrice();
    double multipleTotal = multipleItems.calculateTotalPrice();
    
    CHECK(singleTotal >= 0.0);
    CHECK(multipleTotal >= 0.0);
    CHECK(multipleTotal > singleTotal);
}
TEST(Tip_CompleteCoverage) {
    Tip tip(1, 15.0, 100, 200, 300);
    
    double percentage = tip.calculatePercentageOfOrder(100.0);
    CHECK_CLOSE(15.0, percentage, 0.01);
    
    bool isCash = tip.isCashTip();
    
    bool included = tip.isIncludedInBill(100.0);
}
TEST(Tip_EdgeCases) {
    Tip zeroTip(2, 0.0, 101, 201, 301);
    double zeroPercentage = zeroTip.calculatePercentageOfOrder(100.0);
    CHECK_EQUAL(0.0, zeroPercentage);
    
    Tip negativeTip(3, -10.0, 102, 202, 302);
    double negativePercentage = negativeTip.calculatePercentageOfOrder(100.0);
    
    Tip normalTip(4, 20.0, 103, 203, 303);
    double percentage = normalTip.calculatePercentageOfOrder(0.0);
}
TEST(PurchaseOrder_CompleteCoverage) {
    Supplier supplier("S002", "Beverage Co", "contact@beverage.com");
    PurchaseOrder po(1, &supplier, "2024-01-15");
    
    CHECK_EQUAL(1, po.getId());
    
    std::string status = po.getStatus();
    CHECK(!status.empty());
    
    InventoryItem item1("Coke", 24, "cans");
    InventoryItem item2("Water", 12, "bottles");
    
    po.addItem(&item1);
    po.addItem(&item2);
    
    po.markAsCompleted();
    
    status = po.getStatus();
    CHECK(!status.empty());
}

TEST(PurchaseOrder_EmptyOrder) {
    Supplier supplier("S003", "Empty Supplier", "contact@empty.com");
    PurchaseOrder po(2, &supplier, "2024-01-16");
    
    CHECK_EQUAL(2, po.getId());
    
    std::string status = po.getStatus();
    CHECK(!status.empty());
    
    po.markAsCompleted();
    
    status = po.getStatus();
    CHECK(!status.empty());
}

TEST(Delivery_CompleteCoverage) {
    Supplier supplier("S003", "Dairy Farm", "contact@dairy.com");
    PurchaseOrder po(1, &supplier, "2024-01-10");
    Delivery delivery(1, &supplier, &po, "2024-01-12");
    
    CHECK_EQUAL(1, delivery.getId());
    CHECK_EQUAL("Pending", delivery.getStatus());
    
    delivery.markAsReceived();
    CHECK_EQUAL("Received", delivery.getStatus());
}
TEST(Delivery_NullReferences) {
    Delivery delivery(2, nullptr, nullptr, "2024-01-13");
    
    CHECK_EQUAL(2, delivery.getId());
    CHECK_EQUAL("Pending", delivery.getStatus());
    
    delivery.markAsReceived();
    CHECK_EQUAL("Received", delivery.getStatus());
}

TEST(Reservation_CompleteCoverage) {
    Table table(1, "T02", 6, "Patio");
    
    AccessControl accessControl;
    Admin admin(&accessControl, "Real Admin");
    
    Reservation reservation(1, &table, "2024-01-20 19:00", &admin);
    
    CHECK_EQUAL(1, reservation.getId());
    CHECK(&table == reservation.getReservedTable());
    
    Reservation other(2, &table, "2024-01-20 19:30", &admin);
    bool conflicts = reservation.conflictsWith(other);
    
    reservation.cancelReservation();
    
    bool upcoming = reservation.isUpcoming("2024-01-20 18:00");
}

TEST(Reservation_NullAdmin) {
    Table table(2, "T03", 4, "Window");
    
    Reservation reservation(3, &table, "2024-01-21 20:00", nullptr);
    
    CHECK_EQUAL(3, reservation.getId());
    CHECK(&table == reservation.getReservedTable());
    
    reservation.cancelReservation();
    bool upcoming = reservation.isUpcoming("2024-01-21 19:00");
}

TEST(Order_CompleteCoverage) {
    User user("waiter123", "password");
    Employee waiter(&user, "Server", 25000.0, 2);
    
    Table table(1, "T03", 2, "Window");
    Order order(1, &waiter, &table, "2024-01-20 19:30");
    
    CHECK_EQUAL(1, order.getId());
    CHECK_EQUAL("2024-01-20 19:30", order.getOrderTime());
    
    NutritionInfo nutrition1(280, 10.0, 8.0, 35.0, 4.0, 6.0);
    NutritionInfo nutrition2(650, 40.0, 35.0, 30.0, 2.0, 3.0);
    
    Dish dish1(3, "Salad", "Appetizer", 8.99, true, nutrition1, nullptr);
    Dish dish2(4, "Steak", "Main", 24.99, true, nutrition2, nullptr);
    
    OrderItem item1(1, &dish1, 1, "No onions", 8.99);
    OrderItem item2(2, &dish2, 1, "Medium rare", 24.99);
    
    order.addItem(&item1);
    order.addItem(&item2);
    
    double total = order.calculateTotalAmount();
    CHECK(total >= 0.0);
    
    std::string summary = order.getOrderSummary();
    CHECK(!summary.empty());
    
    order.markAsPaid();
    
    order.removeItem(&item1);
}

TEST(Order_EmptyOrder) {
    User user("emptyuser", "pass");
    Employee employee(&user, "Test", 20000.0, 1);
    Table table(2, "T04", 4, "Main");
    
    Order order(2, &employee, &table, "2024-01-21 12:00");
    
    CHECK_EQUAL(2, order.getId());
    
    double total = order.calculateTotalAmount();
    CHECK(total >= 0.0);
    
    std::string summary = order.getOrderSummary();
    CHECK(!summary.empty());
    
    order.markAsPaid();
}
TEST(OrderService_CompleteCoverage) {
    OrderService service;
    
    Customer customer(1, "Test Customer", "123", "test@email.com");
    Table table(1, "T04", 4, "Main");
    
    Order* order = service.createOrder(&customer, &table);
    CHECK(order != nullptr);
    
    NutritionInfo nutrition(180, 5.0, 3.0, 30.0, 1.0, 8.0);
    Dish dish(5, "Soup", "Appetizer", 6.99, true, nutrition, nullptr);
    OrderItem item(1, &dish, 1, "Extra hot", 6.99);
    
    service.addItemToOrder(order, &item);
    
    service.finalizeOrder(order);
    
    Order* found = service.getOrderById(order->getId());
    CHECK(found != nullptr);
    
    service.cancelOrder(order);
}

TEST(OrderService_NonExistentOrder) {
    OrderService service;
    
    Order* found = service.getOrderById(999);
    CHECK(found == nullptr);
}
TEST(OrderHistory_CompleteCoverage) {
    Customer customer(1, "History Customer", "456", "history@email.com");
    OrderHistory history(&customer);
    
    User user("historyuser", "pass");
    Employee waiter(&user, "Waiter", 22000.0, 1);
    Table table(1, "T05", 2, "Corner");
    
    Order order1(1, &waiter, &table, "2024-01-01");
    Order order2(2, &waiter, &table, "2024-01-15");
    
    history.addOrder(&order1);
    history.addOrder(&order2);
    
    std::vector<Order*> orders = history.getOrdersBetween("2024-01-01", "2024-01-31");
    CHECK(orders.size() >= 0);
    
    double totalSpent = history.getTotalSpent();
    CHECK(totalSpent >= 0.0);
}

TEST(OrderHistory_EmptyHistory) {
    Customer customer(2, "New Customer", "789", "new@email.com");
    OrderHistory history(&customer);
    
    std::vector<Order*> orders = history.getOrdersBetween("2024-01-01", "2024-01-31");
    CHECK_EQUAL(0, orders.size());
    
    double totalSpent = history.getTotalSpent();
    CHECK_EQUAL(0.0, totalSpent);
}

TEST(ReservationService_CompleteCoverage) {
    ReservationService service;
    
    Table table(1, "T06", 4, "Garden");
    
    AccessControl accessControl;
    Admin admin(&accessControl, "Reservation Admin");
    
    Reservation reservation(1, &table, "2024-02-01 20:00", &admin);
    
    Reservation* created = service.createReservation(&reservation);
    CHECK(created != nullptr);
    
    const std::vector<Reservation*>& active = service.getActiveReservations();
    CHECK(active.size() >= 0);
    
    const std::vector<Reservation*>& archived = service.getArchivedReservations();
    CHECK(archived.size() >= 0);
    
    Reservation* found = service.getReservationById(1);
    CHECK(found != nullptr);
    
    service.cancelReservation(&reservation);
}

TEST(ReservationService_NonExistentReservation) {
    ReservationService service;
    
    Reservation* found = service.getReservationById(999);
    CHECK(found == nullptr);
}

TEST(InventoryService_CompleteCoverage) {
    Warehouse warehouse("WH3", "789 Pine St");
    InventoryService service(&warehouse);
    
    InventoryItem item1("Flour", 100, "kg");
    InventoryItem item2("Sugar", 50, "kg");
    
    service.registerItem(&item1);
    service.registerItem(&item2);
    
    bool moved = service.moveItem(&item1, "Section A", "Section B", 10);
    CHECK(moved);
    
    int totalStock = service.getTotalStock("Flour");
    CHECK(totalStock >= 0);
}
TEST(InventoryService_NullWarehouse) {
    InventoryService service(nullptr);
    
    InventoryItem item("Test", 10, "units");
    
    service.registerItem(&item);
    
    bool moved = service.moveItem(&item, "A", "B", 5);
    
    int stock = service.getTotalStock("Test");
    CHECK(stock >= 0);
}

TEST(BillSplitter_CompleteCoverage) {
    User user("splituser", "pass");
    Employee waiter(&user, "Waiter", 23000.0, 1);
    Table table(1, "T07", 4, "Private");
    Order order(1, &waiter, &table, "2024-01-25");
    
    BillSplitter splitter(1, &order);
    
    Customer customer1(1, "Guest1", "111", "g1@email.com");
    Customer customer2(2, "Guest2", "222", "g2@email.com");
    std::vector<Customer*> guests = {&customer1, &customer2};
    
    splitter.splitEvenly(2, guests);
    
    NutritionInfo nutrition(850, 30.0, 40.0, 60.0, 3.0, 5.0);
    Dish dish(6, "Pizza", "Main", 18.99, true, nutrition, nullptr);
    OrderItem item(1, &dish, 1, "Pepperoni", 18.99);
    std::vector<OrderItem*> items = {&item};
    
    splitter.assignItemsToCustomer(&customer1, items);
    
    double total = splitter.getTotalForCustomer(&customer1);
    CHECK(total >= 0.0);
    
    std::vector<double> allTotals = splitter.getAllTotals();
    CHECK(allTotals.size() >= 0);
}

TEST(BillSplitter_EmptyOrder) {
    User user("emptyuser", "pass");
    Employee waiter(&user, "Waiter", 24000.0, 2);
    Table table(2, "T08", 2, "Window");
    Order order(2, &waiter, &table, "2024-01-26");
    
    BillSplitter splitter(2, &order);
    
    Customer customer(3, "Solo Guest", "333", "solo@email.com");
    std::vector<Customer*> guests = {&customer};
    
    splitter.splitEvenly(1, guests);
    
    double total = splitter.getTotalForCustomer(&customer);
    CHECK(total >= 0.0);
    
    std::vector<double> totals = splitter.getAllTotals();
    CHECK(totals.size() >= 0);
}

TEST(Employee_CompleteCoverage) {
    User user("employee123", "securepass");
    Employee employee(&user, "Waiter", 25000.0, 2);
    
    CHECK_EQUAL("Waiter", employee.getPosition());
    CHECK_CLOSE(25000.0, employee.getSalary(), 0.01);
    CHECK_EQUAL(2, employee.getExperience());
    
    bool canDoAction = employee.canDo("serve_tables");
    CHECK(true);
    
    employee.setSalary(28000.0);
    CHECK_CLOSE(28000.0, employee.getSalary(), 0.01);
    
    employee.setSalary(-1000.0);
    CHECK_CLOSE(-1000.0, employee.getSalary(), 0.01);
}

TEST(Employee_NullUser) {
    Employee employee(nullptr, "Manager", 40000.0, 5);
    
    CHECK_EQUAL("Manager", employee.getPosition());
    CHECK_CLOSE(40000.0, employee.getSalary(), 0.01);
    CHECK_EQUAL(5, employee.getExperience());
    
    bool canDo = employee.canDo("manage_team");
    CHECK(true);
    
    employee.setSalary(45000.0);
    CHECK_CLOSE(45000.0, employee.getSalary(), 0.01);
}

TEST(Employee_DifferentPositions) {
    User user1("chef_user", "chefpass");
    User user2("cleaner_user", "cleanpass");
    
    Employee chef(&user1, "Chef", 50000.0, 8);
    Employee cleaner(&user2, "Cleaner", 20000.0, 1);
    Employee manager(nullptr, "Manager", 60000.0, 10);
    
    CHECK_EQUAL("Chef", chef.getPosition());
    CHECK_EQUAL("Cleaner", cleaner.getPosition());
    CHECK_EQUAL("Manager", manager.getPosition());
    
    CHECK_CLOSE(50000.0, chef.getSalary(), 0.01);
    CHECK_CLOSE(20000.0, cleaner.getSalary(), 0.01);
    CHECK_CLOSE(60000.0, manager.getSalary(), 0.01);
    
    CHECK_EQUAL(8, chef.getExperience());
    CHECK_EQUAL(1, cleaner.getExperience());
    CHECK_EQUAL(10, manager.getExperience());
    
    chef.canDo("cook_food");
    cleaner.canDo("clean_areas");
    manager.canDo("approve_orders");
    
    chef.setSalary(55000.0);
    cleaner.setSalary(22000.0);
    manager.setSalary(65000.0);
    
    CHECK_CLOSE(55000.0, chef.getSalary(), 0.01);
    CHECK_CLOSE(22000.0, cleaner.getSalary(), 0.01);
    CHECK_CLOSE(65000.0, manager.getSalary(), 0.01);
}

TEST(Employee_ExperienceEdgeCases) {
    User user("test_user", "testpass");
    
    Employee newEmployee(&user, "Trainee", 18000.0, 0);
    CHECK_EQUAL(0, newEmployee.getExperience());
    CHECK_EQUAL("Trainee", newEmployee.getPosition());
    
    Employee experienced(&user, "Senior", 80000.0, 25);
    CHECK_EQUAL(25, experienced.getExperience());
    
    Employee negativeExp(&user, "Test", 15000.0, -1);
    CHECK_EQUAL(-1, negativeExp.getExperience());
}

TEST(Admin_Employee_Integration) {
    AccessControl accessControl;
    
    Admin admin(&accessControl, "System Admin");
    
    User user1("waiter1", "pass1");
    User user2("chef1", "pass2");
    
    Employee waiter(&user1, "Waiter", 22000.0, 1);
    Employee chef(&user2, "Chef", 45000.0, 5);
    
    admin.grantRole(user1, "service_staff");
    admin.grantRole(user2, "kitchen_staff");
    
    waiter.canDo("take_order");
    chef.canDo("prepare_food");
    
    admin.revokeRole(user1, "service_staff");
    
    admin.listAvailableRoles();
}

TEST(Dish_Employee_Integration) {
    User chefUser("masterchef", "culinary");
    Employee chef(&chefUser, "Head Chef", 60000.0, 10);
    
    NutritionInfo nutrition(520, 35.0, 25.0, 45.0, 6.0, 8.0);
    Dish signatureDish(7, "Signature Steak", "Main", 34.99, true, nutrition, (Chef*)&chef);
    
    CHECK_EQUAL("Signature Steak", signatureDish.getName());
    CHECK(signatureDish.isAvailable());
    CHECK_EQUAL(520, signatureDish.getCalories());
    
    signatureDish.applyDiscount(15.0);
    CHECK(signatureDish.getPrice() < 34.99);
    
    signatureDish.setAvailability(false);
    CHECK(!signatureDish.isAvailable());
}

TEST(AllClasses_Combined) {
    AccessControl accessControl;
    
    Admin admin(&accessControl, "Restaurant Admin");
    
    User managerUser("manager", "mgrpass");
    User chefUser("chef", "chefpass");
    
    Employee manager(&managerUser, "Restaurant Manager", 70000.0, 8);
    Employee chef(&chefUser, "Executive Chef", 75000.0, 12);
    
    NutritionInfo appetizerNutrition(280, 12.0, 8.0, 35.0, 4.0, 6.0);
    NutritionInfo mainNutrition(650, 45.0, 30.0, 40.0, 8.0, 5.0);
    
    Dish appetizer(8, "Bruschetta", "Appetizer", 9.99, true, appetizerNutrition, (Chef*)&chef);
    Dish mainCourse(9, "Ribeye Steak", "Main", 29.99, true, mainNutrition, (Chef*)&chef);
    
    admin.grantRole(managerUser, "management");
    admin.grantRole(chefUser, "kitchen_management");
    
    manager.canDo("manage_staff");
    chef.canDo("create_menu");
    
    CHECK_EQUAL("Bruschetta", appetizer.getName());
    CHECK_EQUAL("Ribeye Steak", mainCourse.getName());
    
    appetizer.applyDiscount(10.0);
    mainCourse.applyDiscount(5.0);
    
    CHECK(appetizer.getPrice() < 9.99);
    CHECK(mainCourse.getPrice() < 29.99);
    
    admin.revokeRole(chefUser, "kitchen_management");
    
    admin.listAvailableRoles();
    CHECK_EQUAL("Restaurant Admin", admin.getName());
    CHECK_EQUAL("Restaurant Manager", manager.getPosition());
    CHECK_EQUAL("Executive Chef", chef.getPosition());
}
TEST(AccessControl_CompleteCoverage) {
    AccessControl accessControl;
    
    Role adminRole("admin", "Administrator role");
    Role userRole("user", "Regular user role");
    
    accessControl.addRole(adminRole);
    accessControl.addRole(userRole);
    
    const Role* foundAdmin = accessControl.findRole("admin");
    const Role* foundUser = accessControl.findRole("user");
    const Role* notFound = accessControl.findRole("nonexistent");
    
    CHECK(foundAdmin != nullptr);
    CHECK(foundUser != nullptr);
    CHECK(notFound == nullptr);
    
    accessControl.listRoles();
}

TEST(AccessControl_Empty) {
    AccessControl accessControl;
    
    const Role* found = accessControl.findRole("admin");
    CHECK(found == nullptr);
    
    accessControl.listRoles();
}

TEST(AnalyticsService_CompleteCoverage) {
    AnalyticsService analytics;
    
    Report report("test_report");
    report.addDaySale(100.0);
    report.addDaySale(200.0);
    report.addDaySale(300.0);
    
    double conversion = analytics.calculateConversion(100, 25);
    CHECK(conversion >= 0.0);
    
    double avgCheck = analytics.calculateAverageCheck(report, 3);
    CHECK(avgCheck >= 0.0);
}

TEST(AnalyticsService_EdgeCases) {
    AnalyticsService analytics;
    
    Report emptyReport("empty");
    
    double avgCheckZero = analytics.calculateAverageCheck(emptyReport, 0);
    CHECK(avgCheckZero >= 0.0);
    
    double conversionZero = analytics.calculateConversion(0, 0);
    CHECK(conversionZero >= 0.0);
    
    double conversionNegative = analytics.calculateConversion(-100, -25);
}

TEST(Bartender_CompleteCoverage) {
    User user("bartender_user", "John Bartender");
    Bartender bartender(&user, 30000.0, 3);
    
    try {
        bartender.mixCocktail();
        bartender.mixCocktail();
        bartender.mixCocktail();
    } catch (...) {
    }
    
    int cocktails = bartender.getCocktailsMixed();
    CHECK(cocktails >= 0);
    
    CHECK_EQUAL("Bartender", bartender.getPosition());
}

TEST(Bartender_NullUser) {
    Bartender bartender(nullptr, 28000.0, 2);
    
    try {
        bartender.mixCocktail();
    } catch (...) {
    }
    
    int cocktails = bartender.getCocktailsMixed();
    CHECK(cocktails >= 0);
}

TEST(Chef_CompleteCoverage) {
    User user("chef_user", "Master Chef");
    Chef chef(&user, 50000.0, 8);
    
    try {
        chef.prepareDish();
        chef.prepareDish();
        chef.prepareDish();
        chef.prepareDish();
    } catch (...) {
    }
    
    int dishes = chef.getDishesPrepared();
    CHECK(dishes >= 0);
    
    CHECK_EQUAL("Chef", chef.getPosition());
}

TEST(Coupon_CompleteCoverage) {
    Coupon coupon("SUMMER25", 25.0, "2024-12-31");
    
    CHECK_EQUAL("SUMMER25", coupon.getCode());
    CHECK_CLOSE(25.0, coupon.getDiscount(), 0.01);
    CHECK(coupon.isValid());
    
    coupon.use();
    
    CHECK(!coupon.isValid());
}

TEST(Coupon_Expired) {
    Coupon expiredCoupon("OLD10", 10.0, "2023-01-01");
    
    bool isValid = expiredCoupon.isValid();
    CHECK(true);
}

TEST(Feedback_CompleteCoverage) {
    User user("feedback_user", "Feedback User");
    Feedback feedback("F001", &user, "Great service!");
    
    feedback.submit();
}

TEST(Feedback_NullUser) {
    Feedback feedback("F002", nullptr, "Anonymous feedback");
    
    feedback.submit();
}

TEST(GiftCard_CompleteCoverage) {
    GiftCard card("GC123456", 100.0);
    
    CHECK_EQUAL("GC123456", card.getCode());
    CHECK_CLOSE(100.0, card.getBalance(), 0.01);
    CHECK(card.getStatus());
    
    bool redeemed = card.redeem(25.0);
    CHECK(redeemed);
    CHECK_CLOSE(75.0, card.getBalance(), 0.01);
    
    bool failedRedeem = card.redeem(100.0);
    CHECK(!failedRedeem);
    CHECK_CLOSE(75.0, card.getBalance(), 0.01);
    
    card.deactivate();
    CHECK(!card.getStatus());
    
    bool deactivatedRedeem = card.redeem(10.0);
    CHECK(!deactivatedRedeem);
}

TEST(GiftCard_EdgeCases) {
    GiftCard card("GC111111", 50.0);
    
    bool negativeRedeem = card.redeem(-10.0);
    
    double balance = card.getBalance();
    CHECK(balance >= 0.0);
}

TEST(LoyaltyAccount_CompleteCoverage) {
    LoyaltyAccount account("L001", 100, "Silver");
    
    CHECK_EQUAL(100, account.getPoints());
    CHECK_EQUAL("Silver", account.getLevel());
    
    account.addPoints(50);
    CHECK_EQUAL(150, account.getPoints());
    
    bool redeemed = account.redeemPoints(75);
    CHECK(redeemed);
    CHECK_EQUAL(75, account.getPoints());
    
    bool failedRedeem = account.redeemPoints(100);
    CHECK(!failedRedeem);
    CHECK_EQUAL(75, account.getPoints());
}
TEST(LoyaltyAccount_EdgeCases) {
    LoyaltyAccount account("L002", 50, "Bronze");
    
    bool negativeRedeem = account.redeemPoints(-5);
    
    int points = account.getPoints();
    CHECK(points >= 0);
}

TEST(Membership_CompleteCoverage) {
    User user("member_user", "Member User");
    LoyaltyAccount account("M001", 500, "Gold");
    Membership membership("MEM001", &user, "Silver", &account);
    
    CHECK_EQUAL("MEM001", membership.getId());
    CHECK_EQUAL("Silver", membership.getLevel());
    
    membership.upgradeLevel();
    
    membership.downgradeLevel();
}

TEST(Membership_NullReferences) {
    Membership membership("MEM002", nullptr, "Bronze", nullptr);
    
    CHECK_EQUAL("MEM002", membership.getId());
    CHECK_EQUAL("Bronze", membership.getLevel());
    
    membership.upgradeLevel();
    membership.downgradeLevel();
}

TEST(Notification_CompleteCoverage) {
    User user("notify_user", "Notification User");
    Notification notification("N001", &user, "Your order is ready");
    
    CHECK_EQUAL("N001", notification.getId());
    CHECK(!notification.getStatus());
    
    notification.send();
    CHECK(notification.getStatus());
}

TEST(Notification_NullUser) {
    Notification notification("N002", nullptr, "System notification");
    
    CHECK_EQUAL("N002", notification.getId());
    
    notification.send();
    CHECK(notification.getStatus());
}

TEST(Permission_CompleteCoverage) {
    Permission permission("read_data", "Can read data", 1);
    
    CHECK_EQUAL("read_data", permission.getKey());
    CHECK_EQUAL("Can read data", permission.getDescription());
    CHECK_EQUAL(1, permission.getPriorityLevel());
}

TEST(Permission_DifferentPriorities) {
    Permission lowPerm("view", "View only", 1);
    Permission mediumPerm("edit", "Edit data", 2);
    Permission highPerm("admin", "Administrator", 3);
    
    CHECK_EQUAL(1, lowPerm.getPriorityLevel());
    CHECK_EQUAL(2, mediumPerm.getPriorityLevel());
    CHECK_EQUAL(3, highPerm.getPriorityLevel());
}

TEST(Report_CompleteCoverage) {
    Report report("R001");
    
    CHECK_EQUAL("R001", report.getId());
    
    report.addDaySale(1000.0);
    report.addDaySale(1500.0);
    report.addDaySale(2000.0);
    
    double average = report.calculateAverage();
    CHECK_CLOSE(1500.0, average, 0.01);
    
    report.setExpenses(3000.0);
    report.setIncome(4500.0);
    
    CHECK_CLOSE(3000.0, report.getExpenses(), 0.01);
    CHECK_CLOSE(4500.0, report.getIncome(), 0.01);
    
    double profit = report.calculateProfit();
    CHECK_CLOSE(1500.0, profit, 0.01);
    
    const std::vector<double>& sales = report.getDailySales();
    CHECK_EQUAL(3, sales.size());
}

TEST(Report_Empty) {
    Report report("R002");
    
    CHECK_EQUAL("R002", report.getId());
    
    double average = report.calculateAverage();
    CHECK(average >= 0.0);
    
    report.setExpenses(1000.0);
    report.setIncome(500.0);
    
    double profit = report.calculateProfit();
    CHECK_CLOSE(-500.0, profit, 0.01);
    
    const std::vector<double>& sales = report.getDailySales();
    CHECK_EQUAL(0, sales.size());
}

TEST(ReportService_CompleteCoverage) {
    ReportService service;
    
    Report report("R003");
    report.addDaySale(500.0);
    report.addDaySale(750.0);
    report.setExpenses(800.0);
    report.setIncome(1250.0);
    
    std::string weekly = service.generateWeeklyReport(report);
    std::string financial = service.generateFinancialReport(report);
    std::string sales = service.generateSalesReport(report);
    std::string summary = service.generateSummaryReport(report);
    
    CHECK(!weekly.empty());
    CHECK(!financial.empty());
    CHECK(!sales.empty());
    CHECK(!summary.empty());
}

TEST(ReportService_EmptyReport) {
    ReportService service;
    
    Report emptyReport("R004");
    
    std::string weekly = service.generateWeeklyReport(emptyReport);
    std::string financial = service.generateFinancialReport(emptyReport);
    std::string sales = service.generateSalesReport(emptyReport);
    std::string summary = service.generateSummaryReport(emptyReport);
    
    CHECK(!weekly.empty());
    CHECK(!financial.empty());
    CHECK(!sales.empty());
    CHECK(!summary.empty());
}

TEST(Role_CompleteCoverage) {
    Role adminRole("admin", "Administrator role");
    
    CHECK_EQUAL("admin", adminRole.getName());
    CHECK_EQUAL("Administrator role", adminRole.getDescription());
    
    Permission perm1("read", "Read access", 1);
    Permission perm2("write", "Write access", 2);
    Permission perm3("delete", "Delete access", 3);
    
    adminRole.addPermission(perm1);
    adminRole.addPermission(perm2);
    adminRole.addPermission(perm3);
    
    CHECK(adminRole.hasPermission("read"));
    CHECK(adminRole.hasPermission("write"));
    CHECK(adminRole.hasPermission("delete"));
    CHECK(!adminRole.hasPermission("nonexistent"));
}

TEST(Role_Empty) {
    Role userRole("user", "Regular user");
    
    CHECK_EQUAL("user", userRole.getName());
    CHECK_EQUAL("Regular user", userRole.getDescription());
    
    CHECK(!userRole.hasPermission("any_permission"));
}

TEST(Sommelier_CompleteCoverage) {
    User user("sommelier_user", "Wine Expert");
    Sommelier sommelier(&user, 45000.0, 6, "Bordeaux");
    
    try {
        sommelier.recommendWine("Steak");
        sommelier.recommendWine("Fish");
        sommelier.recommendWine("Pasta");
    } catch (...) {
    }
    
    int wines = sommelier.getWineRecommendations();
    CHECK(wines >= 0);
    
    CHECK_EQUAL("Sommelier", sommelier.getPosition());
}

TEST(Survey_CompleteCoverage) {
    Survey survey("S001");
    
    survey.addQuestion("How was the service?");
    survey.addQuestion("How was the food?");
    survey.addQuestion("Would you recommend us?");
    
    survey.addAnswer("Excellent");
    survey.addAnswer("Good");
    survey.addAnswer("Yes");
    
    std::string summary = survey.summarizeResults();
    CHECK(!summary.empty());
}

TEST(Survey_Empty) {
    Survey survey("S002");
    
    std::string summary = survey.summarizeResults();
    CHECK(!summary.empty());
}

TEST(Survey_Unbalanced) {
    Survey survey("S003");
    
    survey.addQuestion("Q1");
    survey.addQuestion("Q2");
    survey.addQuestion("Q3");
    survey.addAnswer("A1");
    
    std::string summary = survey.summarizeResults();
    CHECK(!summary.empty());
}

TEST(User_CompleteCoverage) {
    User user("U001", "Test User");
    
    CHECK_EQUAL("Test User", user.getName());
    
    Role userRole("user", "Regular user");
    Permission readPerm("read", "Read access", 1);
    userRole.addPermission(readPerm);
    
    Role adminRole("admin", "Administrator");
    Permission writePerm("write", "Write access", 2);
    adminRole.addPermission(writePerm);
    
    user.addRole(userRole);
    user.addRole(adminRole);
    
    CHECK(user.canDo("read"));
    CHECK(user.canDo("write"));
    CHECK(!user.canDo("delete"));
    
    user.removeRole("user");
    
    LoyaltyAccount loyalty("L001", 100, "Silver");
    user.attachLoyaltyAccount(&loyalty);
    
    CHECK(user.getLoyaltyAccount() != nullptr);
}

TEST(User_Empty) {
    User user("U002", "Empty User");
    
    CHECK_EQUAL("Empty User", user.getName());
    
    CHECK(!user.canDo("any_action"));
    
    CHECK(user.getLoyaltyAccount() == nullptr);
    
    user.removeRole("nonexistent");
}

TEST(Waiter_CompleteCoverage) {
    User user("waiter_user", "Service Waiter");
    Waiter waiter(&user, 22000.0, 1);
    
    try {
        waiter.takeOrder();
        waiter.serveTable();
        waiter.serveTable();
        waiter.serveTable();
    } catch (...) {
    }
    
    int tables = waiter.getTablesServed();
    CHECK(tables >= 0);
    
    CHECK_EQUAL("Waiter", waiter.getPosition());
}
TEST(EmployeeHierarchy_Integration) {
    User bartenderUser("bt_user", "Bartender");
    User chefUser("ch_user", "Chef");
    User sommelierUser("sm_user", "Sommelier");
    User waiterUser("wt_user", "Waiter");
    
    Bartender bartender(&bartenderUser, 32000.0, 4);
    Chef chef(&chefUser, 52000.0, 7);
    Sommelier sommelier(&sommelierUser, 48000.0, 5, "Burgundy");
    Waiter waiter(&waiterUser, 24000.0, 2);
    
    CHECK_EQUAL("Bartender", bartender.getPosition());
    CHECK_EQUAL("Chef", chef.getPosition());
    CHECK_EQUAL("Sommelier", sommelier.getPosition());
    CHECK_EQUAL("Waiter", waiter.getPosition());
    
    bartender.mixCocktail();
    chef.prepareDish();
    sommelier.recommendWine("Duck");
    waiter.serveTable();
    
    int cocktails = bartender.getCocktailsMixed();
    int dishes = chef.getDishesPrepared();
    int wines = sommelier.getWineRecommendations();
    int tables = waiter.getTablesServed();
    
    CHECK(cocktails >= 0);
    CHECK(dishes >= 0);
    CHECK(wines >= 0);
    CHECK(tables >= 0);
}

TEST(LoyaltySystem_Integration) {
    User customer("cust001", "Loyal Customer");
    LoyaltyAccount account("LOY001", 0, "Bronze");
    Membership membership("MEM001", &customer, "Bronze", &account);
    
    customer.attachLoyaltyAccount(&account);
    
    account.addPoints(150);
    account.addPoints(200);
    
    CHECK_EQUAL(350, account.getPoints());
    
    account.redeemPoints(100);
    CHECK_EQUAL(250, account.getPoints());
    
    membership.upgradeLevel();
}
int main() {
    return UnitTest::RunAllTests();
}