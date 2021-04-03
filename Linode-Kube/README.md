# Linode Tutorial with Kubernetes Engine
### Just a basic-intermediate Overview about what we learn

Linode kubernetes engine which is a container orchestration system that combines Lin ODEs ease-of-use and pricing along with the infrastructure efficiency of kubernetes and with lke you don't have to pay for the master node or any cluster management fees all you have to worry about are the nodes themselves which are running your workloads so let's get started deploying a kubernetes cluster here you're viewing my linear cloud manager's dashboard I'll navigate to the kubernetes section of the manager to begin you can see a listing of all the clusters I've already deployed right here so let's go ahead and create a new cluster by clicking on the add a cluster link I can now provide the settings needed to deploy my cluster

first I'll assign it a name let's say my - lke - cluster I'll select a cluster region let's go with Dallas Texas the kubernetes version I'll choose is 1.17 now I can start adding node pools to my cluster and a node pool is a group of
the nodes within a cluster that all have
the same compute resources so for
example

I can add nodes to the pool from
our standard plan dedicated CPU and high
memory plans I'll go ahead and add 3 -
gigabyte the notes by incrementing the
value here and clicking on the Add
button here on the right side 

I can view
a summary of my clusters node pool along
with the clusters total cost let's go
ahead and deploy our kubernetes cluster
by clicking on create cluster as the
cluster is deploying I can view the
summary page that provides more details
about the cluster like its kubernetes
api endpoint it's version region and
links to either download or view its
cube config file I can also add tags to
the cluster for organizational purposes
and down here in the node
section 

I can view the status of all my
clusters notes to start interacting with
my kubernetes cluster using cube CTL the
kubernetes command line tool I'll grab
the clusters cube config file using the
download option I can also directly copy
the contents of the queue config file
from the manager if I prefer to do it
that way I can see that my file has
downloaded so now navigate to my
terminal to get started viewing my
terminal I'll save my cube config file
path to the cube config environment
variable so I can access it with cube
CTL now go ahead and use cube CTL to
view my clusters nodes and here you can
see that their status is displaying
ready which means 

I can begin
interacting with my cluster and define
the resources needed by my workload that
concludes today's demo where I showed
you how to deploy a kubernetes cluster
using the Linode kubernetes engine if
you're interested in diving a little bit
deeper one really great use case is
hosting a docker registry to store your
container images.

**THANKS!**
