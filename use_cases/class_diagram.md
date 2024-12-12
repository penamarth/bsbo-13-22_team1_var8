# Диаграмма классов UML для информационной системы жилищного агентства

![class_diagram](/assets/plantuml/class_diagram.svg)

<!--
```plantuml
@startuml

class App {
-cur_user: User
-chat: Chat
-adverts: Advert[]
+open_chat();
+send_message();
+get_new_messages();
+create_advert();
+set_advert_info(room_num, address);
+make_advert_do_smth();
+fetch_adverts();
+filter_adverts_cheap_first();
+get_first_found_advert();
}

interface AdvertState {
+do_smth();
}

class ActiveAdvert {}

class InactiveAdvert {}

class Advert {
-state: AdvertState
-room_num: int
-address: string
-cost: double
+get_cost(): double;
+set_room_num(room_num);
+set_adress(address);
+set_cost(cost);
+activate();
+diactivate();
+do_smth();
}

Advert o-> AdvertState
ActiveAdvert --\> Advert
InactiveAdvert --\> Advert
ActiveAdvert --|> AdvertState
InactiveAdvert --|> AdvertState

class Chat {
-one: User
-two: User
-messages: Message[]
+send_message(text);
+get_new_messages();
}

class User {
+user_id: long long
}

App *-- Advert
App *-- Chat
App -- User

Chat -- User

@enduml
```
-->
