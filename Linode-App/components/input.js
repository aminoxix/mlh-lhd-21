import React from 'react'
import { View, TextInput, Button } from 'react-native'

import styles from '../static'
import storage from '../storage'

export function InputField(props) {
  const [value, onChangeText] = React.useState('')
  const saveInput = () => {
    storage.save({
      key: props.keyName,
      data: value
    })
    props.callback(props.parent)
  }
  return (
    <View style={styles.inputFieldView}>
      <TextInput
        style={styles.inputBox}
        onChangeText={text => onChangeText(text)}
        value={value} />
      <Button
        onPress={saveInput}
        color='green'
        title={props.text} />
    </View>
  )
}

export function RefreshButton(props) {
  const refresh = () => {
    props.parent.refresh(props.parent)
  }
  return (
    <Button
      style={styles.refresh}
      onPress={refresh}
      color='green'
      title={'Refresh'} />
  )
}
