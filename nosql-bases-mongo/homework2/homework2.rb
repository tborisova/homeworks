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

db['jokes'].update({ author: 'Dumbledore'}, {:$set => {"black_humor" => true}}, {multi: true, upsert: false})

p 'will show all jokes after update:'
db['jokes'].find({ author: 'Dumbledore' }) do |cursor|
  cursor.each do |joke|
    p joke
  end
end

p 'will show sorted jokes by rating: 1'
sorted_jokes = db['jokes'].find({ :characters => { '$in' => ['Bill Gates', 'Ron Weasley'] } }).sort({rating: -1}).to_a

sorted_jokes.each do |joke|
  p joke
end


# p 'All jokes count:'
# p db['jokes'].find().count

db['jokes'].remove({ :rating => { '$lte' => 7 } })

p 'Jokes after removing rating: lte => 7:'
p db['jokes'].find().count

p 'Jokes with author User1:'
p db['jokes'].find({ author: 'User1' }).count

jokes.drop
users.drop
