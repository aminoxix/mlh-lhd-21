import React, { Component } from 'react'
import { Text, View } from 'react-native'

import styles from '../static'
import { getToken } from '../storage'
import { InputField } from '../components'

export default class Settings extends Component {
  constructor (props) {
    super(props)
    this.state = {
      token: null
    }
    getToken(this)
  }
  render = () => {
    return (
      <View style={styles.beeg}>
        <Text style={styles.heading}>Linode App Settings</Text>
        <View>
          <Text style={styles.heading2}>API Token</Text>
          <InputField keyName='token' text='save API token' callback={getToken} parent={this} />
          <Text style={styles.text}>{'\n'}Saved API token:</Text>
          <Text style={styles.text}>{this.state.token}</Text>
        </View>
        <View>
          <Text style={styles.text}>You can get this @ https://cloud.linode.com/profile/tokens.</Text>
          <Text style={styles.text}>cloud.linode.com &gt; My Profile &gt; API Tokens</Text>
        </View>
      </View>
    )
  }
}
