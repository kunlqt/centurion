# Centurion Database Platform

## Build instructions

### Get Started

### Install docker
Docker is used for building Rocksplicator. Follow the [Docker installation instructions](https://docs.docker.com/engine/installation/) to get Docker running on your system.

### Get Centurion build Docker image

```sh
docker pull vaskomitanov/centurion-devel:latest
```

### Get Centurion source code
```sh
git clone https://github.com/vaskomitanov/centurion.git 
cd centurion
```

### Run Centurion build docker container

#### On Mac OSX and Linux
```sh
docker run -it -w /centurion -v $PWD:/centurion -e HOST_PERMS="$(id -u):$(id -g)" vaskomitanov/centurion-devel bash
```

#### On Windows
* Hard Disk sharing with Docker enabled
```sh
docker run -it -p 8080:8080 -w /centurion -v %cd%:/centurion -e HOST_PERMS="$(id -u):$(id -g)" vaskomitanov/centurion-devel bash
```

### While you are inside the build container
```sh
mkdir -p build && cd build && cmake .. && make
```

## Run instructions
```sh
cd centurionserver &&  ./centurionserver --db /tmp --web /centurion/centurionserver/public --jwt s3kret --log-level 0
```

*Please note that above command will store database in container's /tmp directory that is emphermal storage subject to erase on container shutdown. If you want to persist database files, use host mounted volume as a DB folder

## Example use

REST API + WebSocket

For websocket realtime feed update, using web browser go to: http://localhost:8080
*If you are running the server inside docker container, please make sure the port 8080 is properly exposed and the networking between host and container is properly configured.

The websocket streams in realtime all document IDs affected by INSERT, UPDATE or DELETE operation. Applications can connect to the DB engine using websocket and can listen for these events in realtime.  

For document INSERT, UPDATE AND QUERY:

### Insert document(s)
```
curl -X POST \
  http://127.0.0.1:8080/database_foo/collection_bar \
  -H 'Content-Type: application/json' \
  -d '{
	"student": {	
		"person": {
			"first_name": "vasko",
			"last_name": "mitanov"
		}
	}
}'
```

In case the payload is a single JSON object, document is considered as a single document. In case payload is *array* of JSON objects, all objects are inserted as a separate JSON objects and can be queried as a separate documents. 

### Query documents
SQL Query language, HTTP POST request where content-type is `application/sql` and payload is the SQL query

```
curl -X POST \
  http://127.0.0.1:8080/database_foo \
  -H 'Content-Type: application/sql' \
  -d 'select * from collection_bar where student.person.first_name='\''vasko'\'''
```

### Update document(s)
Updating documents works in a similar way as inserting documents with only one difference. The URL path contains ID (or list of IDs) of documents to be updated

```
curl -X POST \
  http://127.0.0.1:8080/database_foo/collection_bar/12345 \
  -H 'Content-Type: application/json' \
  -d '{
	"student": {	
		"person": {
			"first_name": "vaskoz",
			"last_name": "zmitanovq"
		}
	}
}'
```

### Delete document(s)

Deleting documents works in a similar way as updating documents. The method is DELETE and the url path contains list of documents to be deleted

```
curl -X DELETE \
  http://127.0.0.1:8080/database_foo/collection_bar/12345 
```
