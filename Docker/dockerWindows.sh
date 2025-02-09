docker pull fedora
docker run --name heisenberg fedora /bin/bash -v ~/Programming/:/workspace -w /workspace
docker run --name Cpp --rm  -u $(id -u):$(id -g) -v /Programming/:/workspace -w /workspace -it Cpp/Cpp:fedora  /bin/bash
docker ps
docker exec -it heinsenberg bash
docker stop heinsenberg
docker start heinsenberg


docker create --name  cpp -t -i -v c:/Users/felip/Programming:/Programming fedora /bin/bash
docker start cpp
docker exec -it cpp bash
docker stop cpp
docker start cpp

docker create --name  youtube-t -i -v c:/Users/felip/Programming:/Programming fedora /bin/bash
docker start youtube
docker exec -it youtube bash
docker stop youtube
docker start youtube

docker create --name  youtube  -it -v c:/Users/felip/Videos:/Videos fedora /bin/bash
docker start youtube
docker exec -it youtube bash
docker stop youtube
docker start youtube