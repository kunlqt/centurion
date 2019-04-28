# Centurion Database Platform

Centurion Database Platform is:

* Cross-platform, Linux/MacOSX/Windows compatible, document Oriented Database accessible thru simple REST API and Websocket;
* Documents are stored in JSON format;
* All fields of the stored documents are automatically indexed. Currently only string and number JSON fields are indexed;
* SQL query language is used to query database (please see the examples under "Querying documents" section);
* Websocket interface to the core of the web server (experimental feature). All mutations to database documents (storing new documents, modification of current documents and deletion of documents) will cause **sending notifications to websocket connected clients**. Notification/s contain information of updated documents;
* Access to database API is using JWT tokens;

## Build instructions

Docker:
For easy and portable building process, there is a preconfigured Docker build image. In order to build the project from source, you will need to clone this repo, get the build docker image, run the build image and build the source code within the docker container.
Please be aware there are some inconsistencies between Windows docker and Mac OSX/Linux docker (environment variables, mounting drives and command line arguments for CURL). 

Or native:
- For Linux, GCC(supporting at least C++11) can be used to build this project.
- For native Windows build, Visual Studio 2017+ can be used.
- For Mac OSX, XCode can be used to build this project.

### Getting Started

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
cd centurionserver &&  ./centurionserver --ip 0.0.0.0 --db /tmp --web /centurion/centurionserver/public --jwt s3kret --log-level 0
```

*Please note that above command will store database in container's /tmp directory that is emphermal storage subject to erase on container shutdown. If you want to persist database files, use host mounted volume as a DB folder

## Example use

REST API + WebSocket

For websocket realtime feed update, using web browser go to: http://localhost:8080
*If you are running the server inside docker container, please make sure the port 8080 is properly exposed and the networking between host and container is properly configured.

The websocket streams in realtime all document IDs affected by INSERT, UPDATE or DELETE operation. Applications can connect to the DB engine using websocket and can listen for these events in realtime.  

For document INSERT, UPDATE AND QUERY:

### Inserting document(s)
```
curl -X POST \
  http://localhost:8080/db1/collection1 \
  -H 'Content-Type: application/json' \
  -d '[
{
	"student": {	
		"person": {
			"first_name": "Jane",
			"last_name": "Doe",
			"age": 34
		},
		"degree": "bsc"
	}
},
{
	"student": {	
		"person": {
			"first_name": "John",
			"last_name": "Doe",
			"age": 35
		},
		"degree": "bsc"
	}
},
{
	"student": {	
		"person": {
			"first_name": "Albert",
			"last_name": "Einstein",
			"age": 60
		},
		"degree": "phd"
	}
},
{
	"student": {	
		"person": {
			"first_name": "Enrico",
			"last_name": "Fermi",
			"age": 65
		},
		"degree": "phd"
	}
},
{
	"student": {	
		"person": {
			"first_name": "Max",
			"last_name": "Planck",
			"age": 80
		},
		"degree": "phd"
	}
}
]'
```

In case the payload is a single JSON object, document is considered as a single document. In case payload is *array* of JSON objects, all objects are inserted as a separate JSON objects and can be queried as a separate documents. 

*NOTE: Please be aware CURL for Windows does NOT accept single quotes in command line arguments. You will need to use double quotes instead. In this case, double quotes used in the JSON body needs to be escaped. Other option is to reference the request body as a file (using @file.name) 

### Querying documents
SQL Query language, HTTP POST request where content-type is `application/sql` and payload is the SQL query.
In the *SELECT* statement you can extract subset of fields instead of using `SELECT *` to return complete objects. In case subset is selected, then DB will create new JSON objects made of merged fields of SELECT statement.
SQL supports: `AND`, `OR`, `(`, `IN`, `=`, `>`, `<`, `>=`, `<=` and arithmetic operations. There is still a lot of work that needs to be done to wire-up SQL parser with internal DB indices.

```
curl -X POST \
  http://localhost:8080/db1 \
  -H 'Content-Type: application/sql' \
  -d 'select student.person.last_name,student.degree,student.person.age from collection1 where student.person.first_name='\''Albert'\'' or student.person.first_name='\''Enrico'\'' or (student.person.age=30+5 and student.person.last_name='\''Doe'\'')'
 ```
*NOTE: Please be aware CURL for Windows does NOT accept single quotes in command line arguments. You will need to use double quotes instead. In this case, double quotes used in the SQL expression body needs to be escaped. Other option is to reference the request body as a file (using @file.name) 

### Update document(s)
Updating documents works in a similar way as inserting documents with only one difference. The URL path contains ID (or list of IDs) of documents to be updated

```
curl -X POST \
  http://localhost:8080/database_foo/collection_bar/12345 \
  -H 'Content-Type: application/json' \
  -d '{
	"student": {	
		"person": {
			"first_name": "vaskoz",
			"last_name": "mitanov"
		}
	}
}'
```

### Delete document(s)

Deleting documents works in a similar way as updating documents. The method is DELETE and the url path contains list of documents to be deleted

```
curl -X DELETE \
  http://localhost:8080/database_foo/collection_bar/12345 
```

### Roadmap

* Support for multiple Databases, support for multiple DB collections (currently DB name is ignored);
* Implement Document ID generation service;
* Able to exclude certain field in the indexing process (currently all fields are indexed);
* Fix and publish all unit tests covering DB functionality (currently tests are not published);
* Websocket and messaging functionality needs to be completed (current state is just PoC);
* Enabling user access levels (currently JWT is built but not enabled and no user access system is in place);
* Data partitioning and clustering;

### Notes
Following external tools were used for this project:
* JWT support by [JWT cpp](https://github.com/pokowaka/jwt-cpp)
* Amazing header only logging library [SPDLog](https://github.com/gabime/spdlog)
* Ultra fast JSON parser library [RapidJSON](https://github.com/Tencent/rapidjson)
* For networking layer and local filesystem management in portable way, [Boost libraries](https://github.com/boostorg)
* Indexes are internally managed thru [RocksDB](https://github.com/facebook/rocksdb)
* SQL grammar parser is generated using [CPP target for Antlr4](https://github.com/antlr/antlr4/tree/master/runtime/Cpp)

### License
GPLv3
