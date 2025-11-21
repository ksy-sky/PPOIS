| #  | Класс              | Поля | Методы | Ассоциации                           |
|----|--------------------|------|--------|--------------------------------------|
| 1  | user               | 4    | 6      | 2-> Role, LoyaltyAccount             |
| 2  | Admin              | 2    | 4      |                                      |
| 3  | AccessControl      | 1    | 3      | 1-> Role                             |
| 4  | Bartender          | 1    | 2      |                                      |
| 5  | Chef               | 1    | 2      |                                      |
| 6  | Employee           | 4    | 5      | 1-> User                             |
| 7  | loyaltyAccount     | 3    | 4      |                                      |
| 8  | permission         | 3    | 3      |                                      |
| 9  | role               | 3    | 4      | 1-> Permission                       |
| 10 | sommelier          | 2    | 3      |                                      |
| 11 | waiter             | 1    | 3      |                                      |
| 12 | report             | 5    | 9      |                                      |
| 13 | reportService      | 0    | 4      | 1-> Report                           |
| 14 | AnalyticsService   | 0    | 2      | 1-> Report                           |
| 15 | feedback           | 1    | 3      | 1-> User                             |
| 16 | giftcard           | 3    | 5      |                                      |
| 17 | membership         | 4    | 4      | 2-> User, LoyaltyAccount             |
| 18 | notification       | 4    | 3      | 1-> User                             |
| 19 | coupon             | 4    | 5      |                                      |
| 20 | survey             | 3    | 3      |                                      |
| 21 | InventoryItem      | 3    | 8      |                                      |
| 22 | Invoice            | 4    | 6      | 1-> PaymentSource                    |
| 23 | PaymentSource      | 7    | 12     |                                      |
| 24 | Supplier           | 3    | 4      |                                      |
| 25 | Warehouse          | 3    | 8      | 1-> InventoryItem                    |
| 26 | OrderService       | 2    | 5      | 4-> Order, OrderItem, Customer, Table|
| 27 | ReservationService | 2    | 5      | 1-> Reservation                      |
| 28 | Tip                | 5    | 3      |                                      |
| 29 | BillSplitter       | 5    | 4      | 3-> Order, OrderItem, Customer       |
| 30 | OrderHistory       | 2    | 4      | 2-> Order, Customer                  |
| 31 | Reservation        | 5    | 5      | 2-> Admin, Table                     |
| 32 | OrderItem          | 5    | 3      | 1-> Dish                             |
| 33 | Order              | 6    | 5      | 3-> Employee, Table, OrderItem       |
| 34 | Table              | 5    | 3      | 1-> Order                            |
| 35 | Customer           | 6    | 8      | 2-> Order, Reservation               |
| 36 | InventoryService   | 3    | 3      | 2-> Warehouse, InventoryItem         |
| 37 | AuditLog           | 2    | 3      |                                      |
| 38 | PurchaseOrder      | 5    | 4      | 2-> Supplier, InventoryItem          |
| 39 | QualityCheck       | 4    | 4      | 1-> Delivery                         |
| 40 | Delivery           | 5    | 3      | 2-> Supplier, PurchaseOrder          |
| 41 | Dish               | 8    | 7      | 2-> NutritionInfo, Chef              |
| 42 | Ingredient         | 5    | 6      | 1-> Supplier                         |
| 43 | Menu               | 5    | 4      | 2-> Admin, Dish                      |
| 44 | NutritionInfo      | 6    | 8      |                                      |
| 45 | Recipe             | 5    | 12     | 3-> Warehouse, Chef, Ingredient      |
| 46 | KitchenStation     | 6    | 5      | 2-> CookingTask, Chef                |
| 47 | CookingTask        | 7    | 11     | 3-> Recipe, Chef, KitchenStation     |
| 48 | SeasonalMenu       | 4    | 3      | 2-> Admin, Dish                      |
| 49 | Drink              | 6    | 5      | 1-> NutritionInfo                    |
| 50 | Dessert            | 6    | 5      | 2-> NutritionInfo, Chef              |
| 51 | KitchenSchedule    | 4    | 3      | 2-> CookingTask, Chef                |
| 52 | Utensil            | 4    | 5      | -> KitchenStation                   |
| 53 | Appliance          | 5    | 5      | -> KitchenStation                   |
