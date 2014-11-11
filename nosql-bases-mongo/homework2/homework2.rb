# encoding: UTF-8
# coding: UTF-8
# -*- coding: UTF-8 -*-

require 'mongo'
require 'bson'

client = Mongo::MongoClient.new('localhost', 27017)
db     = client['homework1']
jokes = db['jokes']
users = db['users']

jokes_to_insert = [ { author: "Господин Бъзик", text: "Бил Гейтс казал на жена си:
                    ­  Вчера ходих до банката за заем.
                    ­  Чакай, за какво ти е на теб заем?
                    ­  Не на мен. На банката…", rating: 6, characters: ["Бил Гейтс"] }, 
                    { author: "Дъмбълдор", text: "Хари се връща от Забранената гора и казва на Рон: Събрах 
                      гъбки за професор Снейп. Рон: А ако са отровни? Хари: Какво значи 'ако'?", rating: 10,
                      characters: ["Хари Потър", "Снейп", "Рон Уизли"] },
                    { author: "Студент", text: "Двама студенти си говорят: Как мислиш, математическият анализ наука,
                      ли е? Не е, ако беше наука щяха най-напред да го опитват върху животни.", rating: 8,
                      characters: ["студенти"] },
                    { author: "Господин Бъзик", text: "Една учителка казала на Иванчо:  Ти защо си написал \"къшта\"?
                      Я излез на дъската и напиши думата двайсет пъти както трябва, за да я запомниш за цял живот!
                      След минутка учителката се обърнала и видяла на черната дъска:
                      @Repeat(\"къща\";20)", rating: 9, characters: ["Иванчо", "учителката"] },
                    { author: "Дъмбълдор", text: "Рон влиза в магазина Трите Метли и дава банкнота от Монополи и казва: 
                      Един плюшен Виктор Крум.   Момче, това не са истински пари!   То и Крум не е истински, ама някой казва ли
                      ви го?", rating: 7, characters: ["Виктор Крум", "Рон Уизли"] } ]

users_to_insert = [ { name: "Господин Бъзик", email: "joke_master@abv.bg", likes: [ "Бил Гейтс", "Чък Норис", "Чапай", "Петка" ] },
                    { name: "Дъмбълдор", email: "dubmbledore@hogwarts.com", likes: [ "Severus Snape", "James Potter" ] },
                    { name: "Студент", email: "example3@abv.bg", likes: [ "Хари Потър", "Чък Норис" ] } ]

jokes_to_insert.each do |joke|
  jokes.insert(joke)
end

users_to_insert.each do |user|
  users.insert(user)
end

updated_jokes = db['jokes'].update({ author: 'Дъмбълдор'}, {'$set' => {"black_humor" => true}}).to_a

updated_jokes.each do |joke|
  p joke
end

sorted_jokes = db['jokes'].find({ :characters => { '$in' => ['Бил Гейтс', 'Рон Уизли'] } }).sort({rating: 1}).to_a

sorted_jokes.each do |joke|
  p joke
end

p db['jokes'].find().count

db['jokes'].remove({ :rating => { '$lte' => 7 } })

p db['jokes'].find().count

count = db['jokes'].find({ author: 'Господин Бъзик' }).count

p count

jokes.drop
users.drop
