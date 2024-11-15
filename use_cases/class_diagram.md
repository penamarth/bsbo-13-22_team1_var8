# Диаграмма классов UML для информационной системы жилищного агентства

![class_diagram](/assets/plantuml/class_diagram.svg)

<!--
```plantuml
@startuml

class App {
+current_user: User
+chats: Chat[]
+load()
+open_chat()
+send_message(text: string)
+close()
}

class DatabaseAdapter <<static>> {
+get_adverts(): Advert[]
+get_rent_flat(): Flat
+get_all_messages(sender: User, recepient: User): Message[]
+get_new_messages(sender: User, recepient: User): Message[]
+send_message(msg: Message, sender: User, recepient: User)
}

class Database <<static>> {
+send_query(query: String): response
}

class Advert {
+flat: Flat
}

class Flat {
+owner: User
+renter: User
+address: String
+room_num: int
}

class Chat {
+sender: User
+recepient: User
+messages: Message[]
+get_full_message_history()
+get_unread_messages()
+send_message(): int
}

class Message {
+date_time: utc_time
+sender: User
+recepient: User
+message: string
}

class User {
+user_id: long long
}

App *-- Chat
App --\> DatabaseAdapter

Chat -- User
Chat o-- Message

DatabaseAdapter o-- Advert
DatabaseAdapter o-- Flat
DatabaseAdapter o-- User
DatabaseAdapter o-- Message

DatabaseAdapter --\> Database

Advert --\> Flat

@enduml
```
-->
