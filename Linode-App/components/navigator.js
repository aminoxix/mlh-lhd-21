import React from 'react'
import { createBottomTabNavigator } from '@react-navigation/bottom-tabs'
import { MaterialIcons, Ionicons, AntDesign } from '@expo/vector-icons'

import styles from '../static'
import {
  SettingsScreen,
  EventsScreen,
  HomeScreen,
} from '../screens'

const Tab = createBottomTabNavigator()

export default function Navigator() {
  return (
    <Tab.Navigator
      initialRouteName="Home" //"Events"
      tabBarOptions={{
        activeTintColor: 'lime',
        style: styles.nav,
      }}
    >
      <Tab.Screen
        name="Home"
        component={HomeScreen}
        options={{
          tabBarLabel: 'Home',
          tabBarIcon: ({ color, size }) => (
            <AntDesign name='home' size={size} color={color} />
          ),
        }}/>
      <Tab.Screen
        name="Events"
        component={EventsScreen}
        options={{
          tabBarLabel: 'Events',
          tabBarIcon: ({ color, size }) => (
            <MaterialIcons name="event-note" size={size} color={color} />
          ),
        }}/>
      <Tab.Screen
        name="Settings"
        component={SettingsScreen}
        options={{
          tabBarLabel: 'Settings',
          tabBarIcon: ({ color, size }) => (
            <Ionicons name='md-switch' size={size} color={color} />
          ),
        }}/>
    </Tab.Navigator>
  )
}
