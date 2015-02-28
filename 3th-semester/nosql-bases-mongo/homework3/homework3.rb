require 'mongo'
require 'bson'

client = Mongo::MongoClient.new('localhost', 27017)
db     = client['homework1']
jokes = db['jokes']
users = db['users']

jokes_to_insert = [ { author: "User1", text: "This is joke 1", rating: 6, characters: ["Bill Gates"] }, 
                    { author: "Dumbledore", text: "This is joke 2", rating: 10,
                      characters: ["Harry Potter", "Snape", "Ron Weasley"] },
                    { author: "Student", text: "This is joke 3", rating: 8,
                      characters: ["students"] },
                    { author: "User1", text: "This is joke 4", rating: 9, characters: ["Ivancho", "teacher"] },
                    { author: "Dumbledore", text: "This is joke 5", rating: 7, characters: ["Victor", "Ron Weasley"] } ]

users_to_insert = [ { name: "User1", email: "joke_master@abv.bg", likes: [ "Bill Gates", "Chuck Noris", "Chapai", "Petka" ] },
                    { name: "Dumbledore", email: "dubmbledore@hogwarts.com", likes: [ "Severus Snape", "James Potter" ] },
                    { name: "Student", email: "example3@abv.bg", likes: [ "Harry Potter", "Chuck Noris" ] } ]

jokes_to_insert.each do |joke|
  jokes.insert(joke)
end

users_to_insert.each do |user|
  users.insert(user)
end

jokes.aggregate([
    {"$project" => {characters: 1, _id: 0, rating: 1}},
    {"$unwind" => "$characters" },
    {"$group" => {_id: "$characters", count: {"$sum" => 1}, avg: {"$avg" => "$rating"}}},
    {"$sort" => {count: -1}},
    {"$limit" => 3},
    {"$out" => "new_collection"}
  ])

db['new_collection'].find do |cursor|
  cursor.each do |joke|
    p joke
  end
end



db['new_collection'].drop
jokes.drop
users.drop
