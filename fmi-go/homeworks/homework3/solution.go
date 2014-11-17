package main

import (
	"strconv"
	"strings"
	"sync"
	"time"
)

type ExpireMapError struct {
	Message string
}

type ExpireMap struct {
	wg                 sync.WaitGroup
	mini_map_dns       map[string]interface{}
	mini_map_active_to map[string]time.Time
	ch                 chan string
}

func NewExpireMap() *ExpireMap {
	mini_map_dns := make(map[string]interface{})
	mini_map := make(map[string]time.Time)
	ch := make(chan string, 1)
	em := &ExpireMap{mini_map_dns: mini_map_dns, mini_map_active_to: mini_map, ch: ch}

	return em
}

func (em *ExpireMap) Set(key string, value interface{}, expire time.Duration) {
	em.mini_map_active_to[key] = time.Now().UTC().Add(expire)
	em.mini_map_dns[key] = value
	em.wg.Add(em.Size())
	go func(em *ExpireMap, key string, expire time.Duration) {
		<-time.After(expire)
		em.ch <- key
		em.Delete(key)
		em.wg.Done()
	}(em, key, expire)
}

func (em *ExpireMap) Get(key string) (interface{}, bool) {
	value, exists := em.mini_map_dns[key]
	elapsed_time := time.Now().UTC()
	if exists && em.mini_map_active_to[key].After(elapsed_time) {
		return value, true
	} else {
		return nil, false
	}
}

func (em *ExpireMap) GetInt(key string) (int, bool) {
	value, ok := em.Get(key)
	if ok == false {
		return 0, false
	} else if int_val, ok_i := value.(int); ok_i {
		return int_val, ok
	} else {
		return 0, false
	}
}

func (em *ExpireMap) GetFloat64(key string) (float64, bool) {
	value, ok := em.Get(key)
	if ok == false {
		return 0, false
	} else if int_val, ok_i := value.(float64); ok_i {
		return int_val, ok
	} else {
		return 0, false
	}
}

func (em *ExpireMap) GetString(key string) (string, bool) {
	value, ok := em.Get(key)
	if ok == false {
		return "", false
	} else if int_val, ok_i := value.(string); ok_i {
		return int_val, ok
	} else {
		return "", false
	}
}

func (em *ExpireMap) GetBool(key string) (bool, bool) {
	value, ok := em.Get(key)

	if ok == false {
		return false, false
	} else if int_val, ok_i := value.(bool); ok_i {
		return int_val, ok
	} else {
		return false, false
	}
}

func (em *ExpireMap) Expires(key string) (time.Time, bool) {
	if _, ok := em.Get(key); ok {
		return em.mini_map_active_to[key], true
	} else {
		return time.Now(), false
	}
}

func (em *ExpireMap) Delete(key string) {
	delete(em.mini_map_dns, key)
	delete(em.mini_map_active_to, key)
}

func (em *ExpireMap) Contains(key string) bool {
	_, ok := em.Get(key)

	return ok
}

func (em *ExpireMap) Size() int {
	return len(em.mini_map_dns)
}

func (em *ExpireMap) Increment(key string) error {
	value_int, ok_i := em.GetInt(key)
	value_str, ok_s := em.GetString(key)

	if ok_i {
		em.mini_map_dns[key] = value_int + 1
		return nil
	} else if ok_s {
		int_v, _ := strconv.Atoi(value_str)
		int_v += 1
		em.mini_map_dns[key] = strconv.Itoa(int_v)
		return nil
	} else {
		return &ExpireMapError{Message: "wow suuch much"}
	}
}

func (em *ExpireMap) Decrement(key string) error {
	value_int, ok_i := em.GetInt(key)
	value_str, ok_s := em.GetString(key)

	if ok_i {
		em.mini_map_dns[key] = value_int - 1
		return nil
	} else if ok_s {
		int_v, _ := strconv.Atoi(value_str)
		int_v -= 1
		em.mini_map_dns[key] = strconv.Itoa(int_v)
		return nil
	} else {
		return &ExpireMapError{Message: "wow suuch much"}
	}
}

func (e *ExpireMapError) Error() string {
	return e.Message
}

func (em *ExpireMap) ToUpper(key string) error {
	value, ok := em.GetString(key)

	if ok {
		em.mini_map_dns[key] = strings.ToUpper(value)
		return nil
	} else {
		return &ExpireMapError{Message: "wow such much"}
	}
}

func (em *ExpireMap) ToLower(key string) error {
	value, ok := em.GetString(key)

	if ok {
		em.mini_map_dns[key] = strings.ToLower(value)
		return nil
	} else {
		return &ExpireMapError{Message: "wow such much"}
	}
}

func (em *ExpireMap) ExpiredChan() <-chan string {
	return em.ch
}

func (em *ExpireMap) Cleanup() {
	for key, _ := range em.mini_map_dns {
		delete(em.mini_map_dns, key)
		delete(em.mini_map_active_to, key)
	}
}

func (em *ExpireMap) Destroy() {
	go func() {
		em.wg.Wait()
		close(em.ch)
	}()
}
