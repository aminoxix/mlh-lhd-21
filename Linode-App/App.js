import React, { Component } from 'react'
import { StatusBar } from 'expo-status-bar'
import { NavigationContainer } from '@react-navigation/native'

import Tabs from './components/navigator'

export default function App() {
  return (
    <NavigationContainer>
      <Tabs />
      <StatusBar backgroundColor='green' barStyle='dark-content' />
    </NavigationContainer>
  )
}
