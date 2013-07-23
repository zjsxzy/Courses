'''
Coursera:
- Software Defined Networking (SDN) course
-- Module 3 Programming Assignment

Professor: Nick Feamster
Teaching Assistant: Muhammad Shahbaz
'''

from mininet.topo import Topo

class CustomTopo(Topo):
    "Simple Data Center Topology"

    "linkopts - (1:core, 2:aggregation, 3: edge) parameters"
    "fanout - number of child switch per parent switch"
    def __init__(self, linkopts1, linkopts2, linkopts3, fanout=2, **opts):
        # Initialize topology and default options
        Topo.__init__(self, **opts)
        
        # Add your logic here ...
        self.hostNum = 1
        self.swNum = 1
        self.linkopts1 = linkopts1
        self.linkopts2 = linkopts2
        self.linkopts3 = linkopts3
        self.fanout = fanout

        self.creatTree([linkopts1, linkopts2, linkopts3], fanout)

    def creatTree(self, linkopt, fanout, depth=0):
        isSwitch = depth < 3
        if isSwitch:
            node = self.addSwitch("s%s" % self.swNum)
            self.swNum += 1
            for _ in xrange(fanout):
                child_node = self.creatTree(linkopt, fanout, depth + 1)
                self.addLink(node, child_node, **linkopt[depth])
        else:
            node = self.addHost("h%s" % self.hostNum)
            self.hostNum += 1
        return node
        
                    
topos = { 'custom': ( lambda: CustomTopo() ) }